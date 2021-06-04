
#include "../include/libraries.h"

void ui_simple_divider(){
    puts("\n_______________________________\n");
}

void ui_menu_divider(){
    puts("\n*******************************\n");
}

void ui_creator() {

    ui_menu_divider();
    puts("Select the desired option\n"
         "1)Upload an image\n"
         "2)View uploaded images\n"
         "3)Remove image\n"
         "4)Edit image information\n"
         "5)Return to main menu\n");
}

void ui_mode_selection() {
     
    ui_menu_divider();
    puts("Select the mode you want to use\n"
         "1)User\n"
         "2)Creator\n"
         "3)Print system events\n"
         "4)Exit program\n");
}

void ui_user() {

    ui_menu_divider();
    puts("Select the desired option\n"
         "1)Search for an image\n"
         "2)View most downloaded images list\n"
         "3)Return to main menu\n");
        
}

void ui_creator_default_types(){

    ui_simple_divider();
    puts("Select the type of image you wish to upload\n"
        "0) Custom type\n"
        "1) Photo\n"
        "2) Vector\n"
        "3) Graphics\n");
}

