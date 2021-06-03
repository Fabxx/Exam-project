#include "../include/libraries.h"
#include "../include/user_managment.h"
#include "../include/struct.h"
#include "../include/ui_choices_functions.h"
#include "../include/image_management.h"

void getUserData(user *structPtr, int type) {

            int i;
            
            do{
                printf("Insert nickname, max %d lenght:", ID_LENGHT);
                fgets(structPtr->username, ID_LENGHT, stdin);
                i = clear_input_error(structPtr->username);
            }while(i != 0);
    

            do{
                printf("Insert job, max %d lenght: ", ID_LENGHT);
                fgets(structPtr->job, ID_LENGHT, stdin);
                i = clear_input_error(structPtr->job);
            }while(i != 0);
            

    structPtr->type = type;
   
}