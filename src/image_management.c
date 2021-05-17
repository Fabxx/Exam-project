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

int imageFileInit(){
    int success = 0;
    FILE* images;
    
    images = fopen("images.bin","ab+");

    if(images != NULL){
        success = 1;
    }
    fclose(images);

    return success;
}

void writeImage(image newImage, FILE* dest){
    fwrite(&newImage, sizeof(image), 1, dest);
}

image nextImage(FILE* source){
    image data;

    fread(&data, sizeof(image),1,source);
    
    return data;
}

int imageCompare(image source1, image source2){
    int equals = 0;
    int i;

    if(strcmp(source1.author, source2.author)){

        if(source1.downloads == source2.downloads){

            if(strcmp(source1.file_name, source2.file_name)){

                if(strcmp(source1.file_type, source2.file_type)){

                    if(source1.vote == source2.vote){

                        if(strcmp(source1.title, source2.title)){
                            equals = 1;
                            for(i = 0; i < KEYS; i++){
                                if(strcmp(source1.keywords[i], source2.keywords[i]) == 0){
                                    equals = 0;
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

void removeImage(image toRemove){
    int success = 0;
    FILE* images;
    image currentImage;

    images = fopen("images.bin","rb+");

    while(!feof(images) && success == 0){
        currentImage = nextImage(images);

        if(imageCompare(toRemove, currentImage) == 1){

            //I don't feel confident about this one.
            while(!feof(images)){
                fseek(images, -sizeof(image), SEEK_CUR); //Return to position of image to be deleted, go back 1 image
                writeImage(currentImage, images); //Write next image to it
                fseek(images, sizeof(image) * 2, SEEK_CUR); //Go to next image, we are poiting to the image we just removed so we need to skip the now duplicate entry
            }
            //fseek(images, -sizeof(image), SEEK_END); //Go to last duplicate entry
            //fwrite(NULL, sizeof(image), 1, images); //We need to find a better way to remove the last duplicate. 
            success = 1;
        }
    }

    fclose(images);
}

