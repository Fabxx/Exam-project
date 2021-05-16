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
#include "../include/login.h"

void ui_choices() {

    int selection = 0;
    int choice = 0;
    int decision = 0;

        ui_main();
		scanf("%d",&selection);
		fflush(stdin);

		switch(selection) {
			case 1: {
				account_creation();
				break;
			}
			case 2: {
				account_access();
				ui_creator();
                scanf("%d", &decision);
                switch (decision) {
                     case 1: {
                        writeImage();
                        break;
                     }
                     case 2: { //view image funciton

                    break;
                     }
                    case 3: { 
                     removeImage();
                     break;
                    }
                }
				
				break;
			}
		}
    
    ui_mode_selection();
    scanf("%d", &choice);

    switch (choice) {

        case 1: {
                ui_user();
                imageCompare();



                break;
        }
       case 2: {

           break;
       }



    }



}