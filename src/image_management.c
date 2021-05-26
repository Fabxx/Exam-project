
#include "../include/libraries.h"
#include "../include/struct.h"

int imageFileInit(){
    int success = 0;
    FILE* images;
    
    images = fopen("images.dat","ab+");

    if(images != NULL){
        success = 1;
    }
    fclose(images);

    return success;
}

void writeImage(image newImage, FILE* dest, user performer){
    FILE* log;

    fwrite(&newImage, sizeof(image), 1, dest);

    log = fopen("events.log","a");
    fprintf(log, "%s (%s) uploaded \"%s\"\n", performer.username, performer.job, newImage.title);
    fclose(log);
}

image nextImage(FILE* source){
    image data;

    fread(&data, sizeof(image), 1, source);

    return data;
}

int imageCompare(image source1, image source2){
    int equals = 0;
    int i;

    if(strcmp(source1.author, source2.author) == 0) {

        if(source1.downloads == source2.downloads) {

            if(strcmp(source1.file_name, source2.file_name) == 0) {

                if(strcmp(source1.file_type, source2.file_type) == 0) {

                    if(source1.vote == source2.vote){

                        if(strcmp(source1.title, source2.title) == 0) {
                            equals = 1;
                            for(i = 0; i < KEYS; i++) {
                                if(strcmp(source1.keywords[i], source2.keywords[i]) == 0) {
                                    equals = 1;
                                }
                            }
                        }
                    }
                }
            }
        }    
    }
    return equals;
}

void removeImage(int position, user performer){

    image currentImage;
    image deletedImage;
    FILE* fileptr;
    FILE* filetmp;
    FILE* log;

    int i = 0;

    fileptr = fopen("images.dat","r+b");
    filetmp = fopen("temp","w+b");

    while(!feof(fileptr)) {
        fread(&currentImage, sizeof(image), 1, fileptr);
        if(i != position && !feof(fileptr)){
            fwrite(&currentImage, sizeof(image), 1, filetmp);
        }else if(i == position){
            deletedImage = currentImage;
        }
        i++;
    }

    fclose(fileptr);
    fileptr = fopen("images.dat","wb");
    rewind(filetmp);

    while(!feof(filetmp)){
        fread(&currentImage, sizeof(image), 1, filetmp);
        if(!feof(filetmp)){
            fwrite(&currentImage, sizeof(image), 1, fileptr);
        }
    }

    fclose(fileptr);
    fclose(filetmp);
    remove("temp");

    log = fopen("events.log","a");
    fprintf(log, "%s (%s) deleted \"%s\"\n", performer.username, performer.job, deletedImage.title);
    fclose(log);
}

void showImage(image source){
    int i;

    printf("Title: %s (%s) <%s> - By %s\nKeywords: ", source.title, source.file_name, source.file_type, source.author);
    for(i = 0; i < KEYS; i++){
        if(strcmp(source.keywords[i], "") != 0){
            printf("%s - ",source.keywords[i]);
        }else{
            i = KEYS;
            printf("\n");
        }
        
    }
    printf("Downloaded %d times. Rated %.1f/5 (%d)\n", source.downloads, source.vote, source.num_votes);

}

void downloadImage(image toDownload, int position, FILE* dest, user performer) {
    //TODO aggiungere timestamp accanto agli eventi. se abbiamo tempo

    FILE* log;
    
    toDownload.downloads++;
    printf("Downloaded %s\n",toDownload.file_name);

    fseek(dest, sizeof(image) * position, SEEK_SET);
    fwrite(&toDownload, sizeof(image), 1, dest);

    log = fopen("events.log","a");
    fprintf(log, "%s (%s) downloaded \"%s\" By %s\n", performer.username, performer.job, toDownload.title, toDownload.author);
    fclose(log);
}

void addImageVote(image current_image, float image_vote, int img_position ,FILE* images, user performer){

    FILE* log;

    /*
    To each the exact parameter we want to edit, we need to get the initial size of the image
    then for each parameter we sum the size of them with the constans assigned, to reach the vote
    parameter. An image weights 260 bytes, to reach vote we need to get the size of 650 bytes*/

    rewind(images);
    fseek(images, sizeof(image) * img_position + VOTE_POS, SEEK_SET);
  
    current_image.vote = ((current_image.vote * current_image.num_votes) + image_vote) / (current_image.num_votes + 1);
    printf("**%f**",current_image.vote);
    current_image.num_votes++;

    fwrite(&current_image.vote, sizeof(float), 1, images);
    fwrite(&current_image.num_votes, sizeof(int), 1, images);
    
    log = fopen("events.log","a");
    fprintf(log, "%s (%s) voted \"%s\" By %s %.1f/5\n", performer.username, performer.job, current_image.title, current_image.author, image_vote);
    fclose(log);

}

void ui_edit_image_element(char* message, char* original_string, int max_size) {

    char* charptr;
    char* temp;

    temp = (char*) calloc(max_size, sizeof(char));

    puts(message);
    printf("(Current: %s) ", original_string);

    fgets(temp, max_size, stdin);
    if(strcmp(temp, "\n") != 0){
        charptr = strstr(temp, "\n");
        *charptr = 0;
        strcpy(original_string, temp);
    }

    free(temp);

}
