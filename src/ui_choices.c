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
#include "../include/ui_choices_functions.h"

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
                ui_most_downloaded();
                break;
            }
        }
    }
}

void ui_choices_creator() {

    int found_images[SEARCH_MAX_SIZE];
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
                ui_creator_upload_list(currentUser, found_images);
                break;
            }
            case 3: {
                //Remove image
                break;
            }
            case 4: {
                ui_edit_image(currentUser);
                break;
            }
        }
    }
}
