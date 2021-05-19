
#include "../include/ui_choices_functions.h"
#include "../include/struct.h"
#include "../include/image_management.h"

void ui_search_image() {

    image foundList[10];
    image currentImage;
    int found;
    int i, j, foundImages = 0;
    FILE* images;

    images = fopen("images.dat","rb");

    char string[TITLE_SIZE];
    puts("Insert search term: ");
    fgets(string, TITLE_SIZE, stdin);
    string[strlen(string) - 1] = 0;

    i = 0;
    while(!feof(images) && images != NULL) {
        currentImage = nextImage(images);
        found = 1;
        if(strstr(currentImage.title, string) == NULL){
            if(strstr(currentImage.author, string) == NULL){
                found = 0;
                for(j = 0; j < KEYS && found == 0; j++){
                    if(strstr(currentImage.keywords[j], string) != NULL){
                        found = 1;
                    }
                }
            }
        }

        if(found == 1) {
            foundList[foundImages] = currentImage;
            foundImages++;
        }

        //...
    }

    for(i = 0; i < IMAGES; i++) {
        printf("%s\n",foundList[i].title);
    }
    printf("End of the search\n");


}

void ui_most_downloaded() {

    image foundList[10];
    image tmp;
    int i = 0, j = 0, p = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL){
        while(!feof(fileptr) && i < 10) {

            fread(&foundList[i], sizeof(image), 1, fileptr);
            if(!feof(fileptr))
                i++;

        }
        for(j = 0; j < i-1; j++){
            if(foundList[j].downloads > foundList[j+1].downloads) {
                tmp = foundList[j];
                foundList[j] = foundList[j+1];
                foundList[j+1] = tmp;
            }
        }

        printf("Download list:\n");
        for (j = 0; j<i; j++) {

            printf("Title:%s\t"
                "File type:%s\t"
                "File name:%s\t"
                "Number of Downloads:%d\n", foundList[j].title, foundList[j].file_type,
                                        foundList[j].file_name, foundList[j].downloads);

        }
    }

}

void ui_upload(user creator) {
    image new_image;
    int i;
    FILE* images;
    char* charptr;

    images = fopen("images.dat", "a+b");

    puts("Insert Title: ");
    fgets(new_image.title, TITLE_SIZE, stdin);
    charptr = strstr(new_image.title, "\n");
    *charptr = 0;

    puts("Insert file type (extension) : ");
    fgets(new_image.file_type, F_TYPE, stdin);
    charptr = strstr(new_image.file_type, "\n");
    *charptr = 0;

    puts("Insert the file name: ");
    fgets(new_image.file_name, NAME_SIZE, stdin);
    charptr = strstr(new_image.file_name, "\n");
    *charptr = 0;

    for(i = 0; i < KEYS; i++){
        puts("Insert a keyword, leave blank to continue: ");
        fgets(new_image.keywords[i], KEY_LENGHT, stdin);

        if(strcmp(new_image.keywords[i], "\n") == 0){
            i = KEYS;
        }
    }

    strcpy(new_image.author, creator.username);
    new_image.vote = 0;
    new_image.downloads = 0;
    writeImage(new_image, images);
    fclose(images);

}

int ui_upload_list(user creator, image foundList[]) {

    int i = 0, j = 0, p = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL) {
        while(!feof(fileptr) && i < 10) {
            fread(&foundList[i], sizeof(image), 1, fileptr);
            if(!feof(fileptr) && strcmp(foundList[i].author, creator.username) == 0)
                i++;
        }

        printf("Uploads list:\n");
        for (j = 0; j<i; j++) {

            printf("%d) Title:%s\t"
                "File type:%s\t"
                "File name:%s\t"
                "Number of Downloads:%d\t"
                "Author:%s \n", j+1, foundList[j].title, foundList[j].file_type,
                                        foundList[j].file_name, foundList[j].downloads, foundList[j].author);

        }
    }
    fclose(fileptr);
    
    return i;
}

void ui_edit_image(user creator) {
    
    image foundList[10];
    image current_image;
    int images_n, found;
    FILE *fileptr;
    fileptr = fopen("images.dat", "r+b");
    int choice = INT_MAX;

    images_n = ui_upload_list(creator, foundList);

    while(choice > images_n) {
        puts("Select the image you want to edit:\n");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= images_n && choice > 0){
            found = 0;
            while(found == 0 && !feof(fileptr)){
                current_image = nextImage(fileptr);
                found = imageCompare(current_image, foundList[choice - 1]);
                
            }
            if(found == 1){
                //prendiamo la posizione nel file, mediante la dimensione della struttura di riferimento dei dati.
                fseek(fileptr, -sizeof(image), SEEK_CUR);

                //TODO #6 aggiungere funzione di modifica immagine

            }

                
        }

    }

}