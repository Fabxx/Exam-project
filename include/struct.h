/**
 * @file struct.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questra libreria dispone delle strutture dati che permettono di memorizzare i dati utente
 *        e i dati che riguardano gli attributi dei file:
 *         
 *        1)User struct, per i dettagli utente tra cui:
 *          -Nome utente
 *          -Professione
 *          -Tipo di utente, se creatore o utilizzatore. Assume valore 0 se utilizzatore, 1 se creatore.
 *        2)Image struct, per gli attributi dei file, tra cui:
 *          -Titolo del file.
 *          -Tipo del file (png, jpeg, ecc)
 *          -Nome del file
 *          -Parole chiave utilizzate per la ricerca delle immagini
 *          -Voti per la valutazione su cui calcolare la media.
 *          -Numero di download effettuati su un'immagine
 *          -Autore del file.
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "libraries.h"

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct {

    char username[ID_LENGHT];
    char job[ID_LENGHT];
    int type; 

} user;

typedef struct {

    char title[TITLE_SIZE];
    char file_type[F_TYPE]; 
    char file_name[NAME_SIZE]; 
    char keywords[KEYS][KEY_LENGHT];
    float vote;
    int num_votes;
    int downloads;
    char author[ID_LENGHT];
} image;

#endif //STRUCT_H_INCLUDED

