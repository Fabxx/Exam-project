#include "../include/libraries.h"
#include "../include/struct.h"

void makefile() {

    FILE *fileptr;
    fileptr = fopen("account.dat", "w+");
    if (fileptr == NULL) {
        puts("File not created, aborting...\n");
        exit(1);
    }

}


void account_creation(user s) {

    FILE *fileptr;
    fileptr = fopen("account.dat", "r+");
    
    puts("Insert your username\n");
    gets(s.username);
    puts("Confirm username\n");
    gets(s.username_confirm);

    if(strcmp(s.username, s.username_confirm) == 0) {
        puts("Account created\n");
        fprintf(fileptr, "Username:%s\n", s.username);
    } else {
            puts("Username is wrong form previous one, retry.\n");
            account_creation();
    }

}
