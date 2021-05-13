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
 *          -Tipo del file (png, jpeg, ecc)
 *          -Nome del file
 *          -Parole chiave utilizzate per la ricerca delle immagini
 *          -Voti per la valutazione
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
    char username_confirm[ID_LENGHT];
    char job[ID_LENGHT];
    int type; 

} user;

typedef struct {

    char file_type[]; 
    char file_name[]; 
    char keywords[KEY_LENGHT][KEYS]; //KEY_LENGHT = lunghezza parole, KEYS n parole.
    float vote;
    int downloads;
    char author[ID_LENGHT];
    
} image;


#endif //STRUCT_H_INCLUDED

