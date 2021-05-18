/**
 * @file user_managment.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa funzione permette di verificare se mentre si sta creando un account, esso non esista già.
 *        se esiste, ritornerà come valore found e account access mostrerà i relativi messaggi.
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/libraries.h"
#include "../include/user_managment.h"
#include "../include/struct.h"

/*
int userExists(user s[], FILE* fileptr) {
    
    int found = 0;
    int i = 0;

    while(found == 0 && !feof(fileptr)) {
        fread(&s[i].username, sizeof(user), 1, fileptr);
        if (strcmp(s[i].username, s[i].username_confirm) == 0) {
            found = 1;
        }
    }
    return found;
    fclose(fileptr);
}
*/

void getUserData(user *structPtr, int type) {

            char *charptr;
   
            printf("Insert nickname, max %d lenght:", ID_LENGHT);
            fgets(structPtr->username, ID_LENGHT, stdin);
            fflush(stdin);
            charptr = strstr(structPtr->username, "\n");
            *charptr = 0;
    
            printf("Insert job, max %d lenght: ", ID_LENGHT);
            fgets(structPtr->job, ID_LENGHT, stdin);
            fflush(stdin);
            charptr = strstr(structPtr->job, "\n");
            *charptr = 0;
            


    structPtr->type = type;
   
}