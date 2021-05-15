/**
 * @file user_managment.h
 * @author Fabio Spiriticchio - Sergio Mari
 * @brief Questa funzione permette di poter effettuare una verifica sul file, per poter verificare se 
 *        lo username inserito è già esistente o meno alla creazione dell'account.
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef USER_MANAGMENT_H_INCLUDED
#define USER_MANAGMENT_H_INCLUDED

#include "struct.h"

int userExists(user s[], FILE*);

#endif //USER_MANAGMENT_H_INCLUDED