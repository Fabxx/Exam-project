#include "../include/libraries.h"
#include "../include/user_managment.h"
#include "../include/struct.h"

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