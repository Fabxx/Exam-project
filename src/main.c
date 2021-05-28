#include "../include/libraries.h"
#include "../include/ui.h"
#include "../include/struct.h"
#include "../include/user_managment.h"
#include "../include/image_management.h"
#include "../include/ui_choices.h"

int main(void) {
	setbuf(stdout, NULL);
	
	imageFileInit();
	ui_choices();
	puts("Come back soon.\n");

	return (0);

}
