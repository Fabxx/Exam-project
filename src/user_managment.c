#include "../include/libraries.h"
#include "../include/user_managment.h"
#include "../include/struct.h"

int userExists(user s, FILE* fileptr){
    int found = 0;
    user currentUser;

    while(found == 0 && !feof(fileptr)){
        fread(&currentUser, sizeof(user), 1, fileptr);
        if (strcmp(s.username, currentUser.username) != 0) {
            found = 1;
        }
    }

    return found;
}