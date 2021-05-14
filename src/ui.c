
#include "../include/libraries.h"

void ui_main(){

     puts("\t\t\t\t\t|-----Image Hosting System-----|\n"
         "\t\t\t\t\t|---------- v1.0 --------------|\n");

     puts("You need an account to use the service\n"
          "1) New account\n"
          "2) Existing account\n"
          "0) Exit\n");
}

void ui_mode_selection() {
     
    puts("Select the mode you want to use\n"
         "1)User\n"
         "2)Creator\n");
}

void ui_creator() {

    puts("Select the desired option\n"
         
         "1)Upload an image\n"
         "2)View uploaded images\n");

}

void ui_creator_image_options() {
     puts("Select the desired option\n"
          "1) Return to main menu\n"
          "2) Edit image information\n"
          "3) Remove image");
}

void ui_user() {

    puts("Select the desired option\n"
         "1)Search for an image\n"
         "2)List most downloaded");
        
}