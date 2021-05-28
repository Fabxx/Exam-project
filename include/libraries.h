/**
 * @file libraries.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Libreria utilizzata come raccolta di costanti e librerie standard per lo sviluppo del 
 *        sorgente. Le seguenti costanti rappresentano:
 *        1)Lunghezza del username
 *        2)Lunghezza massima della singola parola chiave
 *        3)Numero di parole chiavi
 *        4)Lunghezza del nome del file
 *        5)Lunghezza del titolo di ricerca
 *        6)Lunghezza per descrivere il tipo di file.
 *        7)Dimensione massima per la ricerca.
 *        8)Posizione del voto memorizzato all'interno della struct, questo ci permetterà
 *          di modificare il voto all'interno del file e la media qualora ci fossero nuovi voti
 *          inseriti.
 *        
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef LIBRARIES_H_INCLUDED
#define LIBRARIES_H_INCLUDED

#define ID_LENGHT 30

#define TITLE_SIZE 40
#define F_TYPE 20
#define NAME_SIZE 30
#define KEY_LENGHT 15
#define KEYS 10

#define SEARCH_MAX_SIZE 40

#define VOTE_POS TITLE_SIZE+F_TYPE+NAME_SIZE+(KEY_LENGHT*KEYS)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#endif // LIBRARIES_H_INCLUDED