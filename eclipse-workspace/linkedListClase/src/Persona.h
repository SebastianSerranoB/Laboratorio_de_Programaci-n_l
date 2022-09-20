/*
 * Persona.h
 *
 *  Created on: 1 jun 2022
 *      Author: admin
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
    unsigned int id;
    char name[51];
    char lastName[51];
    char isEmpty;
}Persona;


Persona* persona_new();
void persona_delete(Persona* this);
int persona_setId(Persona* this, unsigned int id);
int persona_getId(Persona* this);
int persona_setName(Persona* this, char* name);
char* persona_getName(Persona* this);
int persona_setLastName(Persona* this, char* lastName);
char* persona_getLastName(Persona* this);
int persona_setIsEmpty(Persona* this, unsigned int isEmpty);
int persona_getIsEmpty(Persona* this);


#endif /* PERSONA_H_ */
