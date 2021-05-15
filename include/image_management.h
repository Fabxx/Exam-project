#ifndef IMAGE_MANAGEMENT_H
#define IMAGE_MANAGEMENT_H

#include "libraries.h"
#include "struct.h"

int imageFileInit();

void writeImage(image, FILE*);
image nextImage(FILE*);
void removeImage(image);
int imageCompare(image, image);

#endif