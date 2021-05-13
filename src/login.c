#include "../include/libraries.h"
#include "../include/struct.h"

void account_creation(user s) {

    FILE *fileptr;
    int exit = 0;

    fileptr = fopen("account.dat", "r+");
    
    while(exit == 0){
        puts("Insert your username: \n");
        gets(s.username);
        puts("Confirm username: \n");
        gets(s.username_confirm);
        
        if(strcmp(s.username, s.username_confirm) == 0) {

            if(!userExists(s,fileptr)){ //Check if username doesn't exist
                puts("Insert your job: \n");
                gets(s.job);
                puts("Account created\n");
                s.type = 1; //Set user type to Creator

                fwrite(&s, sizeof(user), 1, fileptr);

            } else{
                puts("This username is already in use.\n");
                rewind(fileptr);
            }
                    
        } else {
            puts("Username is wrong form previous one.\n");
            rewind(fileptr);
            
        }
    }
    

    fclose(fileptr);
}