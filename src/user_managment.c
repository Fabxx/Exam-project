/**
 * @file user_managment.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief 
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/libraries.h"
#include "../include/user_managment.h"
#include "../include/struct.h"

int userExists(user s[], FILE* fileptr) {
    int found = 0;
    user currentUser;
    int i = 0;

    while(found == 0 && !feof(fileptr)) {
        fread(&currentUser, sizeof(user), 1, fileptr);
        if (strcmp(s[i].username, currentUser.username) != 0) {
            found = 1;
        }
    }
    return found;
    fclose(fileptr);
}