#include "../include/ui_choices.h"
#include "../include/libraries.h"
#include "../include/image_management.h"
#include "../include/ui.h"
#include "../include/login.h"

void ui_choices() {

    int selection = 0;
    int choice = 0;

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
				ui_choices();

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