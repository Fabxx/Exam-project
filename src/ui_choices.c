#include "../include/ui_choices.h"
#include "../include/libraries.h"
#include "../include/image_management.h"
#include "../include/ui.h"

void ui_choices() {

    int choice = 0;
    
    ui_mode_selection();
    scanf("%d", &choice);

    switch (choice) {

        case 1: {
                ui_user();
                

                break;
        }
       case 2: {

           break;
       }



    }



}