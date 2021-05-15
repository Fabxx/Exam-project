#include "../include/libraries.h"
#include "../include/ui.h"
#include "../include/login.h"
#include "../include/file_creation.h"
#include "../include/struct.h"
#include "../include/user_managment.h"

int main(void) {

	int choice = 1;

	makeAccountsFile();

	while(choice != 0) {
		ui_main();
		scanf("%d",&choice);
		fflush(stdin);
		
		switch(choice) {
			case 1: {
				account_creation();
				system("cls");
				break;
			}
			case 2: {
				account_access();
				ui_creator();
				
				break;
			}
		}
	}

	puts("Come back soon");

	return (0);
}