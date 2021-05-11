#include "../include/libraries.h"

void ui(){
     ui_mode_selection();
}

void ui_mode_selection() {

    puts("\t\t\t\t\t|-----Image Hosting System-----|\n"
         "\t\t\t\t\t|---------- v1.0 --------------|\n");
    
    puts("Select the mode you want to use\n"
         "1)User\n"
         "2)Creator\n");
}

void ui_options_display_creator() {

    puts("Select the desired option\n"
         "1)Create an image\n"
         "2)Upload an image\n"
         "3)View rating on image\n");

}

void ui_options_display_user() {

    puts("Select the desired option\n"
         "1)Search for an image\n");
        
         /**
          * @Queste due opzioni devono 
          * essere spostate per quando 
          * l'utente deciderà di cercare
          * un'immagine.
          * "2)Download an image\n"
          * "3)rate a image\n"
          */
}