/**
 * @file ui.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa libreria contiene le funzioni utilizzate per mostrare l'interfaccia utente, e mostratne
 *        le specifiche opzioni, in base al tipo di accesso dell'utente. In ordine le seguenti funzioni
 *        producono questi effetti:
 *          
 *        1)La funzione mostra l'interfaccia utente iniziale, mostrando le due modalità d'accesso.
 *        2)La funzione mostra l'interfaccia creatore, indicandone le opzioni disponibili
 *        3)La funzione mostra l'interfaccia utilizzatore, indicandone le opzioni disponibili
 *        4)La funzione predispone le opzioni disponibili da applicare sulle immagini in modalità creatore
 *         
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

void ui_simple_divider();
void ui_main();
void ui_mode_selection();
void ui_creator();
void ui_user();
void ui_creator_default_types();

#endif //UI_H_INCLUDED
