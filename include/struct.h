#include "../include/libraries.h"

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct {

    char username[ID_LENGHT];
    char profession[ID_LENGHT];
    int type; //1 if creator


} user;

typedef struct {

    char file_type[];
    char file_name[];
    char keywords[25][5]; //25 = lunghezza parole, 5 n parole.
    float vote;
    int downloads;
    char creator[ID_LENGHT];
    
} image;


#endif //STRUCT_H_INCLUDED

