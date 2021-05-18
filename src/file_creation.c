#include "../include/libraries.h"
#include "../include/file_creation.h"

void makeAccountsFile() {

    FILE *fileptr;
    fileptr = fopen("account.dat", "w+b");
    if (fileptr == NULL) {
        puts("File not created, aborting...\n");
        exit(1);
    }

        fclose(fileptr);

}