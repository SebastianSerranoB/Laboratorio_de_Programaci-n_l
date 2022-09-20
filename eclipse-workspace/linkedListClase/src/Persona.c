/*
 * Persona.c
 *
 *  Created on: 1 jun 2022
 *      Author: admin
 */
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

/** \brief
 *
 * \return Persona*
 *
 */
Persona* persona_new()
{
    return malloc(sizeof(Persona));
}

void persona_delete(Persona* this)
{
    free(this);
}

int persona_setId(Persona* this, unsigned int id)
{
    int retorno = -1;
    //validar
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this)
{
    int retorno=-1;
    //falta validar
    if(this != NULL)
        retorno = this->id;

    return retorno;
}

int persona_setName(Persona* this, char* name)
{
    int retorno = -1;
    //falta validar
    if(this != NULL && name != NULL)
    {
        strcpy(this->name, name);
        retorno = 0;
    }
    return retorno;
}

char* persona_getName(Persona* this)
{
    char* retorno = NULL;
    //falta validar
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}

int persona_setLastName(Persona* this, char* lastName)
{
    int retorno=-1;
    //falta validar
    if(this != NULL && lastName != NULL)
    {
        strcpy(this->lastName,lastName);
        retorno = 0;
    }
    return retorno;
}

char* persona_getLastName(Persona* this)
{
    char* retorno=NULL;
    //falta validar
    if(this != NULL)
    {
        retorno = this->lastName;
    }
    return retorno;
}

int persona_setIsEmpty(Persona* this, unsigned int isEmpty)
{
    int retorno=-1;
    //validar
    if(this != NULL && isEmpty >= 0)
    {
        this->isEmpty = isEmpty;
        retorno = 0;
    }
    return retorno;
}

int persona_getIsEmpty(Persona* this)
{
    int retorno = -1;
    //falta validar
    if(this != NULL)
        retorno = this->isEmpty;

    return retorno;
}


