
#include "../include/ui_choices_functions.h"
#include "../include/struct.h"
#include "../include/image_management.h"
#include "../include/ui_edit_element.h"

void ui_search_image() {

    int found_list[SEARCH_MAX_SIZE];
    image current_image;
    int found, choice;
    int i, j, foundImages = 0;
    FILE* images;

    images = fopen("images.dat","rb");

    //Inserimeto del termine di ricerca
    char string[TITLE_SIZE];
    puts("Insert search term: ");
    fgets(string, TITLE_SIZE, stdin);
    string[strlen(string) - 1] = 0;

    //Inizio della ricerca delle immagini
    i = 0;
    while(!feof(images) && images != NULL) {
        //Prendi la prossima immagine
        current_image = nextImage(images);
        if(!feof(images)){
            //Controlla se è nei termini di ricerca
            found = 1;
            if(strstr(current_image.title, string) == NULL){
                if(strstr(current_image.author, string) == NULL){
                    found = 0;
                    for(j = 0; j < KEYS && found == 0; j++){
                        if(strstr(current_image.keywords[j], string) != NULL){
                            found = 1;
                        }
                    }
                }
            }

            //Se è nei termini di ricerca, ricorda la sua posizione
            if(found == 1) {
                found_list[foundImages] = i;
                foundImages++;
            }

            i++;
        }
        
    }

    //Mostra tutte le immagini trovate
    rewind(images);
    for(i = 0; i < foundImages; i++) {
        fseek(images, sizeof(image) * found_list[i], SEEK_SET);
        current_image = nextImage(images);
        printf("%d) %s By %s\n", i + 1, current_image.title, current_image.author);
    }
    printf("End of the search\n");
    
    //Permetti la scelta di visualizzare una immagine trovata
    choice = INT_MAX;
    while(foundImages > 0 && choice > foundImages){
        printf("Choose the image you want to see. 0 to cancel: ");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= foundImages && choice > 0) {

            rewind(images);
            fseek(images, sizeof(image) * (found_list[choice - 1]), SEEK_SET);
            current_image = nextImage(images);

            showImage(current_image);

            //TODO download e valutazione
        }

    }
    

    fclose(images);
}

void ui_most_downloaded() {

    image foundList[10];
    image tmp;
    int i = 0, j = 0;
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
        fclose(fileptr);
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

    //Init keys to empty value. Prevents errors
    for(i = 0; i < KEYS; i++) {
        strcpy(new_image.keywords[i], "");
    }

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

int ui_upload_list(user creator, int foundList[]) {

    image currentImage;
    int i = 0, j = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL) {
        printf("Uploads list:\n");

        while(!feof(fileptr) && i < SEARCH_MAX_SIZE) {
            fread(&currentImage, sizeof(image), 1, fileptr);
            if(!feof(fileptr) && strcmp(currentImage.author, creator.username) == 0){
                foundList[i] = j;
                i++;

                printf("%d) Title:%s\t"
                "File type:%s\t"
                "File name:%s\t"
                "Number of Downloads:%d\t"
                "Author:%s \n", i, currentImage.title, currentImage.file_type,
                                    currentImage.file_name, currentImage.downloads, currentImage.author);
            } 
            j++;
        }
    }
    fclose(fileptr);
    return i;
}

void ui_edit_image(user creator) {
    
    int found_list[SEARCH_MAX_SIZE];
    image current_image;
    int images_n, i;

    int choice = INT_MAX;
    FILE *fileptr;
    fileptr = fopen("images.dat", "r+b");
    
    images_n = ui_upload_list(creator, found_list);

    while(choice > images_n) {
        puts("Select the image you want to edit. 0 to cancel:\n");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= images_n && choice > 0) {

            rewind(fileptr);
            fseek(fileptr, sizeof(image) * (found_list[choice - 1]), SEEK_SET);
            current_image = nextImage(fileptr);
            fseek(fileptr, sizeof(image) * (found_list[choice - 1]), SEEK_SET);

            if(strcmp(creator.username, current_image.author) == 0){
                ui_edit_image_element("Image title (Leave blank for no change) ", current_image.title, TITLE_SIZE);
                fwrite(current_image.title, TITLE_SIZE, 1,  fileptr);

                ui_edit_image_element("Image format (Leave blank for no change) ", current_image.file_type, F_TYPE);
                fwrite(current_image.file_type, F_TYPE, 1,  fileptr);

                ui_edit_image_element("File name (Leave blank for no change) ", current_image.file_name, NAME_SIZE);
                fwrite(current_image.file_name, NAME_SIZE, 1,  fileptr);

                for(i = 0; i < KEYS; i++) {
                    ui_edit_image_element("Insert a keyword (Leave blank to stop editing) ", current_image.keywords[i], KEY_LENGHT);
                    if(strcmp(current_image.keywords[i], "") == 0){
                        i = KEYS; //exit loop
                    }
                }
                fwrite(current_image.keywords, KEY_LENGHT * KEYS, 1, fileptr);

            }else{
                puts("That is not your image.\n");
            }
                
        }

    }

    fclose(fileptr);
}

void ui_download_image(user creator) {

    image foundList[10];    //TODO necesario implementare nuovo metodo di ricerca
    image current_image;
    int images_n, found;
    FILE *fileptr;
    fileptr = fopen("images.dat", "r+b");
    int choice = INT_MAX;
    

    images_n = ui_upload_list(creator, foundList);

    while(choice > images_n) {
        puts("Select the image you want to download:\n");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= images_n && choice > 0){
            found = 0;
            while(found == 0 && !feof(fileptr)) {
                current_image = nextImage(fileptr);
                found = imageCompare(current_image, foundList[choice - 1]);
                
            }
            if(found == 1) {
                //prendiamo la posizione nel file, mediante la dimensione della struttura di riferimento dei dati.
                fseek(fileptr, (long) (sizeof(image)) * -1, SEEK_SET);
                current_image.downloads++;
                writeImage(current_image, fileptr);
            }

        }

                
    }

        fclose(fileptr);
}

