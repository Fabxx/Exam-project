
#include "../include/ui_choices_functions.h"
#include "../include/struct.h"
#include "../include/image_management.h"
#include "../include/ui.h"

void ui_search_image(user performer) {

    int badInput;
    int found_list[SEARCH_MAX_SIZE];
    image current_image;
    int found, choice, decision;
    int i, j, foundImages = 0;
    FILE* images;

    char* string;

    float user_vote = 0;

    images = fopen("images.dat","r+b");
    string = (char*) calloc(TITLE_SIZE, sizeof(char));

    //Inserimeto del termine di ricerca
    
    do{
        printf("Insert search term (max size is %d): ",TITLE_SIZE);
        fgets(string, TITLE_SIZE, stdin);
        badInput = clear_input_error(string);
    }while(badInput);
    

    //Inizio della ricerca delle immagini
    i = 0;
    while(!feof(images) && images != NULL) {
        //Prendi la prossima immagine
        current_image = nextImage(images);
        if(!feof(images)){
            //Controlla se e' nei termini di ricerca
        	stringToLower(string);
            found = 1;
            stringToLower(current_image.title);
            if(strstr(current_image.title, string) == NULL){
            	stringToLower(current_image.author);
                if(strstr(current_image.author, string) == NULL){
                	stringToLower(current_image.file_type);
                    if(strstr(current_image.file_type, string) == NULL)
                    found = 0;
                    for(j = 0; j < KEYS && found == 0; j++){
                    	stringToLower(current_image.keywords[j]);
                        if(strstr(current_image.keywords[j], string) != NULL){
                            found = 1;
                        }
                    }
                }
            }

            //Se e' nei termini di ricerca, ricorda la sua posizione
            if(found == 1) {
                found_list[foundImages] = i;
                foundImages++;
            }

            i++;
        }
        
    }

    //Mostra tutte le immagini trovate
    rewind(images);
    for(i = 0; i < foundImages; i++) {
        fseek(images, sizeof(image) * found_list[i], SEEK_SET);
        current_image = nextImage(images);
        printf("%d) %s By %s\n", i + 1, current_image.title, current_image.author);
    }
    printf("End of the search\n");
    
    //Permetti la scelta di visualizzare una immagine trovata
    choice = INT_MAX;
    while(foundImages > 0 && choice > foundImages){
        printf("Choose the image you want to see. 0 to cancel: ");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= foundImages && choice > 0) {

            rewind(images);
            fseek(images, sizeof(image) * (found_list[choice - 1]), SEEK_SET);
            current_image = nextImage(images);

            //Visualizza l'immagine trovata
            ui_simple_divider();
            showImage(current_image);

            decision = 0;
            do{
                printf("Choose an action\n1) Download\n2) Rate\n0) No action\n\n");
                scanf("%d",&decision);
                fflush(stdin);

                switch(decision){
                    case 1:{
                        //Download
                        downloadImage(current_image, found_list[choice - 1], images, performer);

                        break;
                    }
                    case 2:{
                        //Valutazione
                        user_vote = 0;
                        do{
                            printf("Insert the vote 1 to 5, put 0 to leave empty: ");
                            scanf("%f", &user_vote);
                            fflush(stdin);

                        }while(user_vote < 0 || user_vote > 5);

                        if (user_vote != 0) {
                            addImageVote(current_image, user_vote, found_list[choice - 1], images, performer);
                        }

                        break;
                    }
                }
            }while(decision > 2);
        }

    }
    

    fclose(images);
}

void ui_most_downloaded() { 

    image foundList[10];
    image tmp;
    int i = 0, j = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL) {
        while(!feof(fileptr) && i < 10) {

            fread(&foundList[i], sizeof(image), 1, fileptr);
            if(!feof(fileptr)) {
                i++;
            }
        }

        sortDownloads(foundList, i);

        while(!feof(fileptr)){
            fread(&tmp, sizeof(image), 1, fileptr);
            if(!feof(fileptr)) {
                if(tmp.downloads > foundList[i-1].downloads){
                    foundList[i-1] = tmp;
                    sortDownloads(foundList, i);
                }
            }
        }
        fclose(fileptr);
    }

    ui_simple_divider();
    printf("10 most downloaded images:\n");
    for (j = 0; j < i; j++) {

        printf("%d): %s (%s) By %s, %s [Downloaded %d time/s, rated %.2f (%d)]\n", j+1,
                                                                            foundList[j].title,
                                                                            foundList[j].file_name,
																			foundList[j].author,
                                                                            foundList[j].file_type,
                                                                            foundList[j].downloads,
                                                                            foundList[j].vote,
                                                                            foundList[j].num_votes);


    }
    printf("End of the list\n");
    

}
        
void ui_upload(user creator) {
    image new_image;
    int i, badInput, choice = 0;
    FILE* images;

    images = fopen("images.dat", "a+b");

    //Inserimento Titolo
    do{
        ui_simple_divider();
        puts("Insert Title: ");
        fgets(new_image.title, TITLE_SIZE, stdin);
        badInput = clear_input_error(new_image.title);
    }while(badInput);

    //Inserimento Tipo
    do{
        ui_creator_default_types();
        scanf("%d", &choice);
        fflush(stdin);
    }while(choice < 0 || choice > 3);
    if(choice == 0){
        do{
            ui_simple_divider();
            puts("Insert custom image type: ");
            fgets(new_image.file_type, F_TYPE, stdin);
            badInput = clear_input_error(new_image.file_type);
        }while(badInput);
    }else{
        switch(choice) {
            case 1:{
                strcpy(new_image.file_type, "photo");
                break;
            }
            case 2:{
                strcpy(new_image.file_type, "vectorial");
                break;
            }
            case 3:{
                strcpy(new_image.file_type, "graphical");
                break;
            }
        }
    }
    
    //Inserimento Nome
    do{
        ui_simple_divider();
        puts("Insert the file name (if applicable, the extention too): ");
        fgets(new_image.file_name, NAME_SIZE, stdin);
        badInput = clear_input_error(new_image.file_name);
    }while(badInput);

    //Inizializza le chiavi ad un valore vuoto per evitare errori.
    for(i = 0; i < KEYS; i++) {
        strcpy(new_image.keywords[i], "");
    }

    //Inserimento Chiavi
    for(i = 0; i < KEYS; i++){
        do{
            ui_simple_divider();
            puts("Insert a new keyword, leave blank to stop adding: ");
            fgets(new_image.keywords[i], KEY_LENGHT, stdin);

            badInput = clear_input_error(new_image.keywords[i]);

            if(strcmp(new_image.keywords[i], "") == 0){
                i = KEYS;
            }

        }while(badInput);

        

    }

    strcpy(new_image.author, creator.username);
    new_image.vote = 0;
    new_image.num_votes = 0;
    new_image.downloads = 0;

    writeImage(new_image, images, creator);

    fclose(images);

}

int ui_creator_upload_list(user creator, int foundList[], int mode) {

    image currentImage;
    int i = 0, j = 0;
    int photos = 0, graphical = 0, vectorial = 0, other = 0;
    FILE *fileptr;
    fileptr = fopen("images.dat", "rb");

    if(fileptr != NULL) {
        printf("Uploads list:\n");

        while(!feof(fileptr) && i < SEARCH_MAX_SIZE) {
            fread(&currentImage, sizeof(image), 1, fileptr);
            if(!feof(fileptr) && strcmp(currentImage.author, creator.username) == 0){
                foundList[i] = j;
                i++;

                printf("%d): %s (%s), %s [Downloaded %d time/s, rated %.2f (%d)]\n", i, currentImage.title, currentImage.file_name, currentImage.file_type, currentImage.downloads, currentImage.vote, currentImage.num_votes);

                if(strcmp(currentImage.file_type, "photo") == 0) {
                photos++;
                } else if (strcmp(currentImage.file_type, "vectorial") == 0)
                {
                vectorial++;
                } else if (strcmp(currentImage.file_type, "graphical") == 0)
                {
                graphical++;
                } else
                {
                other++;
                }
            } 
            j++;

        }
        if(mode == 1){
        	printf("Number of uploaded images: %d\n", i);
        	printf("%d photos, %d vectorials, %d graphics and %d of other type\n", photos, vectorial, graphical, other);
        }

        fclose(fileptr);
    }
    
    return i;
}

void ui_edit_image(user creator) {
    
    int found_list[SEARCH_MAX_SIZE];
    image current_image;
    int images_n, i;

    int choice = INT_MAX;
    FILE *fileptr;
    fileptr = fopen("images.dat", "r+b");
    
    images_n = ui_creator_upload_list(creator, found_list, 0);

    while(choice > images_n) {
        puts("Select the image you want to edit. 0 to cancel:\n");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= images_n && choice > 0) {

            rewind(fileptr);
            fseek(fileptr, sizeof(image) * (found_list[choice - 1]), SEEK_SET);
            current_image = nextImage(fileptr);
            fseek(fileptr, sizeof(image) * (found_list[choice - 1]), SEEK_SET);

            if(strcmp(creator.username, current_image.author) == 0){
            	ui_simple_divider();
                ui_edit_image_element("Image title (Leave blank for no change) ", current_image.title, TITLE_SIZE);
                fwrite(current_image.title, TITLE_SIZE, 1,  fileptr);

                ui_simple_divider();
                ui_edit_image_element("Image format (Leave blank for no change) ", current_image.file_type, F_TYPE);
                fwrite(current_image.file_type, F_TYPE, 1,  fileptr);

                ui_simple_divider();
                ui_edit_image_element("File name (Leave blank for no change) ", current_image.file_name, NAME_SIZE);
                fwrite(current_image.file_name, NAME_SIZE, 1,  fileptr);

                for(i = 0; i < KEYS; i++) {
                	ui_simple_divider();
                    ui_edit_image_element("Insert a keyword (Leave blank to stop editing) ", current_image.keywords[i], KEY_LENGHT);
                    if(strcmp(current_image.keywords[i], "") == 0){
                        i = KEYS; //uscita dal for.
                    }
                }
                fwrite(current_image.keywords, KEY_LENGHT * KEYS, 1, fileptr);

            }else{
                puts("That is not your image.\n");
            }
                
        }

    }

    fclose(fileptr);
}

void ui_delete_image(user creator){
    int found_list[SEARCH_MAX_SIZE];
    int images_n;
    int choice = INT_MAX;

    images_n = ui_creator_upload_list(creator, found_list, 0);

    while(choice > images_n) {
        puts("Select the image you want to delete. 0 to cancel:\n");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice <= images_n && choice > 0) {
            removeImage(found_list[choice - 1], creator);
        }
    }
}

void ui_print_logs(){
    FILE* log;
    char* logString;
    //stampa massimo 150 righe nel log.
    logString = (char*)calloc(150, sizeof(char));
    log = fopen("events.log", "r");

    if(log != NULL){
        ui_simple_divider();
        printf("Printing...\n");
        while(!feof(log)){
            fgets(logString, 150, log);
            if(!feof(log)){
                printf("%s",logString);
            }
        }
        fclose(log);
        printf("Done printing\n");
    }else{
        printf("Error displaying events.txt\n");
    }

    free(logString);
}
