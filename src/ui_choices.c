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
    
    user currentUserPtr;
    int decision;

    getUserData(currentUserPtr, 0);

    while(decision != 3) {

        ui_user();
        scanf("%d", &decision);
        fflush(stdin);

        switch (decision) {
            case 1: {
                ui_search_image();
                break;
            }
            case 2: {
                //List most downloaded
                break;
            }
        }
    }
}

void ui_choices_creator() {
    
    user currentUser;
    int decision = 0;

    getUserData(currentUser, 1);

    while(decision != 5) {
        ui_creator();
        scanf("%d", &decision);
        fflush(stdin);

        switch (decision) {
            case 1: {
                //Upload new image
            break;
            }
            case 2: { 
                //Show uploaded images
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

    images = fopen("images.bin","r+b");

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

    for(i = 0; i < foundImages; i++){
        printf("%s\n",foundList[i].title);
    }
    printf("End of the search\n");


}

void ui_download_list() {

    image foundList[10];
    int p;
    image tmp;
    int i, j;

     for (i=0; i<p-1; i++) {

         if(foundList[i].downloads > foundList[i+1].downloads) {

                tmp = foundList[i];
                foundList[i] = foundList[i+1];
                foundList[i+1] = tmp;

         }
         p-=1;
     }      
        
        printf("Download list:\n");
        for (j=0; j<foundList[j]; j++) {

                printf("Title:\t"
                       "File type:\t"
                       "File name:\t"
                       "Number of Downloads:\t", foundList[j].title, foundList[j].file_type, 
                                                 foundList[j].file_name, foundList[j].downloads);
                    
        }


}