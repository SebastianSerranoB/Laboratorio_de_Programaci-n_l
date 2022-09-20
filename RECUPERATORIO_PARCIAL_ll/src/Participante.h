/*
 * Participante.h
 *
 *  Created on: 4 ago 2022
 *      Author: admin
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_

//=========== DECLARACION ENTIDAD ========== //
typedef struct{

	int id;
	char nombre[300];
	int edad;
	int idDificultad;
	int score;
}eParticipante;



eParticipante* Participante_new();
eParticipante* Participante_newParametros(char* id, char* nombre, char* edad, char* idDificultad, char* score);
int Participante_delete(eParticipante* this);

//============ SETTERS ===============//

int Participante_setId(eParticipante* this, int id);
int Participante_setEdad(eParticipante* this, int edad);
int Participante_setScore(eParticipante* this, int score);
int Participante_setNombre(eParticipante* this, char* nombre);
int Participante_setIdDificultad(eParticipante* this, int idDificultad);

//============ GETTERS ===============//

int Participante_getNombre(eParticipante* this, char* name);
int Participante_getId(eParticipante* this, int* id);
int Participante_getEdad(eParticipante* this, int* edad);
int Participante_getScore(eParticipante* this, int* score);
int Participante_getIdDificultad(eParticipante* this, int* idDificultad);
int Participante_getIdDificultadTxt(eParticipante* this, int idTipo, char* dificultadTxt);

//============================================================//

//============ PRINT MENU ============//

int printMenu(int min, int max,char textMenu[]);

//============ PRINT UN_ELEMENTO =============//

int printOneElement(eParticipante* this);

//============ PRINT LISTA_ELEMENTOS ==============//

int printList(LinkedList* this);

//=========== LEER ARCHIVO =============//

// desde aqui, abrimos el archivo, luego llamamos al parser echo a medida de la estructura
int leerArchivo(char* path , LinkedList* this);
int parser_FromText(FILE* pFile, LinkedList* lista);

int ordenarLista(LinkedList* this);
int ordenarPorNombre(void* pPassengerA, void* pPassengerB);

//====filter=============
LinkedList* filtrarLista(LinkedList* this);
int Participante_filtrarPorDificultadFacil(void* elemento);
int Participante_filtrarPorDificultadNormal(void* elemento);
int Participante_filtrarPorDificultadDificil(void* elemento);

//=========== GUARDAR ARCHIVO ==================//

int guardarEnArchivoTxt(char* path , LinkedList* this);



#endif /* PARTICIPANTE_H_ */
