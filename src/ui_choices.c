/**
 * @file ui_choices.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa funzione raccoglie tutte le scelte da fare nei menu, selection gestisce le scelte per
 *        il tipo di account da usare, choice gestisce il tipo di scelte da fare con un account specifico
 *        decision gestisce la scelta su un'immagine fatta
 * @version 0.1
 * @date 2021-05-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/ui_choices.h"
#include "../include/libraries.h"
#include "../include/image_management.h"
#include "../include/ui.h"
#include "../include/struct.h"
#include "../include/user_managment.h"


void ui_choices() {

    int choice = 0;

    while(choice != 3) {

        ui_mode_selection();
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {

            case 1: {
                ui_choices_user();
                break;
            }
            case 2: {
                ui_choices_creator();
                break;
            }
        }
    }
}

void ui_choices_user() {

    user currentUser;
    int decision;

    getUserData(&currentUser, 0);

    while(decision != 4) {

        ui_user();
        scanf("%d", &decision);
        fflush(stdin);

        switch (decision) {
            case 1: {
                ui_search_image();
                break;
            }
            case 2: {
                ui_download_list();
                break;
            }
            case 3: { //TODO #5 Download image function

            }
        }
    }
}

void ui_choices_creator() {

    user currentUser;
    int decision = 0;

    getUserData(&currentUser, 1);

    while(decision != 5) {
        ui_creator();
        scanf("%d", &decision);
        fflush(stdin);

        switch (decision) {
            case 1: {
                ui_upload(currentUser);
                break;
            }
            case 2: {
                ui_upload_list(currentUser);
                break;
            }
            case 3: {
                //Remove image
                break;
            }
            case 4: {
                //Edit image info
                break;
            }
        }
    }
}

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
    while(!feof(images) && images != NULL){
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

void ui_download_list() {

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

void ui_upload_list(user creator) {

    image foundList[10];
    int i = 0, j = 0, p = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL){
        while(!feof(fileptr) && i < 10) {

            fread(&foundList[i], sizeof(image), 1, fileptr);
            if(!feof(fileptr) && strcmp(foundList[i].author, creator.username) == 0)
                i++;

        }

        printf("Uploads list:\n");
        for (j = 0; j<i; j++) {

            printf("Title:%s\t"
                "File type:%s\t"
                "File name:%s\t"
                "Number of Downloads:%d\t"
                "Author:%s \n", foundList[j].title, foundList[j].file_type,
                                        foundList[j].file_name, foundList[j].downloads, foundList[j].author);

        }
    }
        fclose(fileptr);
}
