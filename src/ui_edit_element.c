#include "../include/libraries.h"
#include "../include/struct.h"

void ui_edit_image_element(char* message, char* original_string, int max_size) {

    char* temp;

    temp = (char*) calloc(max_size, sizeof(char));

    puts(message);
    printf("(Current: %s) ", original_string);

    fgets(temp, TITLE_SIZE, stdin);
    if(strcmp(temp, "\n") != 0){
        strcpy(original_string, temp);
    }

    free(temp);

}

void ui_edit_keys(char* message, char** keys, int max_lenght, int max_keys){

    int i;

    for(i = 0; i < max_keys; i++){
        ui_edit_image_element(message, keys[i], max_lenght);
        if(strcmp(keys[i], "") == 0){
            i = max_lenght; //exit loop
        }
    }

}