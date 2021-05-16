/**
 * @file image_management.c
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Libreria per la gestione delle immagini.
 *
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/libraries.h"
#include "../include/struct.h"

int imageFileInit() {
    int success = 0;
    FILE *fileptr;
    
    fileptr = fopen("images.bin","a+b");

    if(fileptr != NULL){
        success = 1;
    }
    fclose(fileptr);

    return success;
}

void writeImage(image arr[], FILE *fileptr) {

    fileptr = fopen("images.bin", "a+b");
    
    int i;

    for(i=0; i<IMAGES; i++) {
        fwrite(&arr[i].file_name, sizeof(image), 1, fileptr);
    }    
        fclose(fileptr);    
}

int nextImage() {

    image arr[IMAGES];
    FILE *fileptr;

    int i;

    fileptr = fopen("images.bin", "a+b");

    fread(&arr[i].file_name, sizeof(image), 1, fileptr);
    fclose(fileptr);

    return nextImage;
}

int imageCompare(image arr[]) {
    int equals = 0;
    int i;

    for(i=0; i< IMAGES; i++) {

        if(strcmp(arr[i].author, arr[i+1].author) == 0) {

        if(arr[i].downloads == arr[i+1].downloads) {

            if(strcmp(arr[i].file_name, arr[i+1].file_name) == 0) {

                if(strcmp(arr[i].file_type, arr[i+1].file_type) == 0) {

                    if(arr[i].vote == arr[i+1].vote){

                        if(strcmp(arr[i+1].title, arr[i+1].title) == 0) {
                            equals = 1;
                            for(i = 0; i < KEYS; i++){
                                if(strcmp(arr[i+1].keywords, arr[i+1].keywords) == 0) {
                                    equals = 0;
                                }
                            }
                        }
                    }
                }
            }
        }    
    }
}
    return equals;
}

void removeImage(int toRemove){
    int success = 0;
    FILE* images;
    int currentImage;

    images = fopen("images.bin","rb+");

    while(!feof(images) && success == 0){
        currentImage = nextImage(images);

        if(imageCompare(toRemove) == 1){

            //I don't feel confident about this one.
            while(!feof(images)){
                fseek(images, -sizeof(image), SEEK_CUR); //Return to position of image to be deleted, go back 1 image
                writeImage(currentImage, images); //Write next image to it
                fseek(images, sizeof(image) * 2, SEEK_CUR); //Go to next image, we are poiting to the image we just removed so we need to skip the now duplicate entry
            }
                fseek(images, -sizeof(image), SEEK_END); //Go to last duplicate entry
                fwrite(NULL, sizeof(image), 1, images); //We need to find a better way to remove the last duplicate. 
                success = 1;
        }
    }

    fclose(images);
}

