#include "../include/libraries.h"
#include "../include/struct.h"

void account_creation() {

    user s[USERS];

    FILE *fileptr;
    int exit = 0;
    int i;

    fileptr = fopen("account.dat", "r+");

    for (i = 0; i < USERS; i++) {
        
        while(exit == 0) {
        
        puts("Insert username: \n");
        gets(s[i].username);
        puts("Confirm username: \n");
        gets(s[i].username_confirm);
        
        if(strcmp(s[i].username, s[i].username_confirm) == 0) {

            if(!userExists(s, fileptr)){ //Check if username doesn't exist
                puts("Insert your job: \n");
                gets(s[i].job);
                puts("Account created. You can now login.\n");
                s[i].type = i % 2;

                fwrite(&s, sizeof(user), 1, fileptr);

                exit = 1;

            } else{
                puts("This username is already in use.\n");
                rewind(fileptr);
            }
                    
        } else {
            puts("Username is wrong form previous one.\n");
            rewind(fileptr);
            
        }
    }
}
    fclose(fileptr);
}

user account_access(int type, user s[]) {

    FILE *fileptr;
    fileptr = fopen("account.dat", "r+");
    int i;

    puts("Insert your username\n");
     
     while(!feof(fileptr)) {

         if (fread(&s[i], sizeof(user), 1, fileptr) == NULL) {

            puts("Username not found.\n");
         } else {
            printf("%d) %s - %s - ",i+1,s[i].username,s[i].job);
            
            if(s[i].type == 1) {
                printf("Creator\n");
            }
                
            else {
                printf("User\n");
            }
                
         }
            
     }

}