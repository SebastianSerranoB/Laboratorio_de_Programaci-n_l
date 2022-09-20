/*
 * Entidad.h
 *
 *  Created on: 4 ago 2022
 *      Author: admin
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

//=========== DECLARACION ENTIDAD ========== //
typedef struct{

	int id;
	char descripcion[300];
	float precio;
	int idTipo;
	int cuotas;
	float precioCuota; // por comodidad, para agregarlas al guardar el archivo
}eComputer;



//============ CONSTRUCTOR ============//

eComputer* Computer_new();
eComputer* Computer_newParametros(char* id, char* descripcion, char* precio, char* idTipo, char* cuotas);

//============ DESTRUCTOR ============//

int Computer_delete(eComputer* this);

//============ SETTERS ===============//

int computer_setId(eComputer* this, int id);
int computer_setIdTipo(eComputer* this, int idTipo);
int computer_setPrecio(eComputer* this, float precio);
int computer_setCuotas(eComputer* this, int cuotas);
int computer_setPrecioCuota(eComputer* this, float precioPorCuota);
int computer_setDescripcion(eComputer* this, char* descripcion);


//============ GETTERS ===============//

int computer_getDescripcion(eComputer* this, char* name);
int computer_getId(eComputer* this, int* id);
int computer_getIdTipo(eComputer* this, int* idTipo);
int computer_getIdTipoTxt(eComputer* this, int idTipo, char* tipo);
int computer_getPrecio(eComputer* this, float* precio);
int computer_getCuotas(eComputer* this, int* cuotas);
int computer_getPrecioCuota(eComputer* this, float* precioPorCuota);

//=======================================================//

//--------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------//

//============ PRINT ========================//

int printMenu(int min, int max,char textMenu[]);

int printList(LinkedList* this);
int printOneElement(eComputer* this);

//--------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------//


//=========== LEER ARCHIVO =============//

int leerArchivo(char* path , LinkedList* this);
int parser_FromText(FILE* pFile, LinkedList* lista);

//=========== GUARDAR ARCHIVO ==================//

int guardarEnArchivoTxt(char* path , LinkedList* this);


//========== SORT ============//

//hace de controller
int ordenarLista(LinkedList* this);

//criterios de ordenamientos
int computer_compararPorCuotas(void* e1, void* e2);

//========= MAP =============//

LinkedList* mapearLista(LinkedList* this);

//criterio de mapeo
int computer_mapearPorCuotas(void* elemento);








#endif /* ENTIDAD_H_ */
