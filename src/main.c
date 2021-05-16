#include "../include/libraries.h"
#include "../include/ui.h"
#include "../include/login.h"
#include "../include/file_creation.h"
#include "../include/struct.h"
#include "../include/user_managment.h"
#include "../include/image_management.h"
#include "../include/ui_choices.h"

int main(void) {

	int choice = 0;

	makeAccountsFile();
	imageFileInit();

		ui_main();
		scanf("%d",&choice);
		fflush(stdin);

		switch(choice) {
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
		puts("Come back soon.\n");

		return (0);
	}
