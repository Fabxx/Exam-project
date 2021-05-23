#include "../include/libraries.h"
#include "../include/struct.h"

void ui_edit_image_element(char* message, char* original_string, int max_size) {

    char* charptr;
    char* temp;

    temp = (char*) calloc(max_size, sizeof(char));

    puts(message);
    printf("(Current: %s) ", original_string);

    fgets(temp, max_size, stdin);
    if(strcmp(temp, "\n") != 0){
        charptr = strstr(temp, "\n");
        *charptr = 0;
        strcpy(original_string, temp);
    }

    free(temp);

}
