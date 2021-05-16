#ifndef IMAGE_MANAGEMENT_H
#define IMAGE_MANAGEMENT_H

#include "libraries.h"
#include "struct.h"

int imageFileInit();

void writeImage(image, FILE*);
void nextImage();
void removeImage();
int imageCompare();

#endif