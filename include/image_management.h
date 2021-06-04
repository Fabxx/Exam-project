/**
 * @file image_management.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Libreria per la gestione delle immagini:
 *  
 *        -ImageFileInit inizializza il file per la memorizzazione delle immagini
 * 
 *        -writeImage scrive i dati delle immagini all'interno del file
 *        -nextImage utilizzato per ricercare l'immagine successiva nel file.
 *        -ImageCompare effettua un confronto tra gli attributi inseriti e gli attributi esistenti nel file.
 *        -removeImage permette di rimuovere un'immagine dal file.
 *        -ui_edit_image_element permette di modificare i parametri dell'immagine caricata.
 * 
 *        -ShowImage permette di mostrare un'immagine dopo la ricerca.
 *        -DownloadImage permette di scaricare un'immagine dal file.
 *        -addImageVote permette di aggiungere un voto su un'immagine specifica e 
 *         ricalcolarne la media.
 *        -sortDownloads ordina la lista delle immagini in base al numero di download di esse.
 *        -Stringtolower permette durante la ricerca, di convertire i caratteri maiuscoli in minuscoli
 *         in modo tale da avere comunque un riscontro positivo nella ricerca se l'elemento esiste.
 *
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IMAGE_MANAGEMENT_H
#define IMAGE_MANAGEMENT_H

#include "libraries.h"
#include "struct.h"

char* getCurrentTime();
int clear_input_error(char[]);

int imageFileInit();

void writeImage(image, FILE*, user);
image nextImage(FILE* source);
int imageCompare(image source1, image source2);
void removeImage(int, user);
void ui_edit_image_element(char*, char*, int);

void showImage(image);
void downloadImage(image, int, FILE*, user);
void addImageVote(image, float, int, FILE*, user);
void sortDownloads(image*, int);

void stringToLower(char*, int);

#endif
