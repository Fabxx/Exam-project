#include "../include/libraries.h"

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct {

    char username[ID_LENGHT];
    char profession[ID_LENGHT];
    int type; //1 if creator

} user;

typedef struct {

    char file_type[]; //usata per l'estensione
    char file_name[]; //usata per il nome
    char keywords[KEY_LENGHT][KEYS]; //KEY_LENGHT = lunghezza parole, KEYS n parole.
    float vote;
    int downloads;
    char creator[ID_LENGHT];
    
} image;


#endif //STRUCT_H_INCLUDED

