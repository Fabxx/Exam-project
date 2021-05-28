/**
 * @file ui_choices.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa libreria contiene le seguenti funzioni che variano la disposizione
 *        delle scelte, a seconda della modalità inserita:
 *          -Mostra opzioni per la tipologia dell'account.
 *          -Mostra le opzioni per il creatore
 *          -Mostra le opzioni per l'utilizzatore
 *          -Mostra la lista dei download per l'utente
 *          -MOstra la lista degli upload per il creatore.
 * @version 0.1
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef UI_CHOICES_H_INCLUDED
#define UI_CHOICES_H_INCLUDED

#include "struct.h"

void ui_choices();
void ui_choices_creator();
void ui_choices_user();
void ui_search_image();
void ui_download_list();
void ui_upload(user currentUser);

#endif // !UI_CHOICES_H_INCLUDED