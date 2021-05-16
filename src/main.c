#include "../include/libraries.h"
#include "../include/ui.h"
#include "../include/login.h"
#include "../include/file_creation.h"
#include "../include/struct.h"
#include "../include/user_managment.h"

int main(void) {

	int choice = 0;

	makeAccountsFile();

		ui_main();
		scanf("%d",&choice);
		fflush(stdin);

		switch(choice) {
			case 1: {
			do {
				account_creation();
			} while(choice == 1);
				break;
			}
			case 2: {
			do {
				account_access();
				ui_creator();
			} while(choice == 2);
				break;
			}
		}
		puts("Come back soon.\n");

		return (0);
	}
