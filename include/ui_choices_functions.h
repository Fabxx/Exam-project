/**
 * @file ui_choices_functions.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa libreria contiene le seguenti funzioni:
 *         -Funzione di ricerca di un'immagine creata all'interno del file.
 *         -Ricerca e ordinamento delle immagini caricate all'interno del file a seconda
 *          del numero di download.
 *         -Funzione per il caricamento di un'immagine all'interno del file da parte del 
 *          creatore
 *         -Funzione che permette al creatore di modificare un'immagine caricata.
 *         -Funzione che permette di visualizzare le immagini caricare da un creatore specifico
 *         -Funzione che permette di eliminare un'immagine caricata dal creatore.
 *         -Funzione stampa gli eventi di sistema
 * @version 0.1
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UI_CHOICES_FUNCTIONS_H_INCLUDED
#define UI_CHOICES_FUNCTIONS_H_INCLUDED
#include "struct.h"

void ui_search_image(user);
void ui_most_downloaded();
void ui_upload(user creator);
void ui_edit_image(user creator);
int ui_creator_upload_list(user creator, int foundList[]);
void ui_delete_image(user creator);
void ui_print_logs();

#endif //UI_CHOICES_FUNCTIONS_H_INCLUDED




