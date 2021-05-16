/**
 * @file login.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Queste funzioni permettono di poter creare un account e accedera ad un account già
 *        esistente. Le funzionalità sono le seguenti:
 *         -Account creation ancor prima di poter permettere di creare un account, verifica se lo
 *          username inserito non esista già all'interno del file account.dat. In caso negativo, 
 *          si procederà a far creare l'account. Per poter definire se un account è creatore o meno
 *          ci si baserà sul valore indice del ciclo, se è pari sarà un account creatore, se dispari, 
 *          sarà un account utente normale.
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/libraries.h"
#include "../include/struct.h"
#include "../include/user_managment.h"
#include "../include/ui.h"

void account_creation() {

    user s[USERS];

    FILE *fileptr;
    int exit = 0;
    int i;

    fileptr = fopen("account.dat", "r+b");

    for (i = 0; i < USERS; i++) {
        
        while(exit == 0) {
        
        puts("Insert username: \n");
        gets(s[i].username);

        if (!userExists(s, fileptr)) { //Check if username doesn't exist
                puts("Insert your job: \n");
                gets(s[i].job);
                puts("Account created. You can now login. Returning to menu...\n");
                s[i].type = i % 2;

                fwrite(&s[i].username, sizeof(user), 1, fileptr);
                exit = 1;
                main();

            } else {
                puts("Username already exist\n");
                rewind(fileptr);
                account_creation();
            }
        }
    }          
        fclose(fileptr);

}

void account_access() {

    user s[USERS];

    FILE *fileptr;
    fileptr = fopen("account.dat", "r+b");
    int i = 0;
    
     while(!feof(fileptr)) {

         for(i=0; i<USERS; i++) {
             if (fread(&s[i].username, sizeof(user), 1, fileptr) == 0) {
                puts("No accounts were found, returning to menu..\n");
                ui_main();
         } else {
            printf("%d) %s - %s - ", i+1, s[i].username, s[i].job);
            
            if(s[i].type == 1) {
                printf("Creator\n");
            } else {
                printf("User\n");
            }

            }       
        }
    }
}