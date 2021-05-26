/**
 * @file image_management.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Libreria per la gestione delle immagini. 
 *        -ImageFileInit inizializza il file per la memorizzazione delle immagini
 *        -writeImage scrive i dati delle immagini all'interno del file
 *        -nextImage utilizzato per ricercare l'immagine successiva nel file, ogni immagine pesa
 *                   260 byte con tutti i suoi dati.
 *        -ImageCompare effettua un confronto tra gli attributi inseriti e gli attributi esistenti nel file.
 *        -removeImage permette di rimuovere un'immagine dal file.
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

int imageFileInit();

void writeImage(image newImage, FILE* dest);
image nextImage(FILE* source);
int imageCompare(image source1, image source2);

void showImage(image);
image downloadImage(image, user);
void addImageVote(image, float, int, FILE*, user);
void removeImage(int);

#endif