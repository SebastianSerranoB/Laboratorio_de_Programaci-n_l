/*
 ============================================================================
 Name        : practicaLinkedList.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	int idAlumno;
	char nombre[51];
	char apellido[51];

}eAlumno;

eAlumno* new_Alumno(void);

int initArrayPunteros(eAlumno* arrayP[], int lenElementos);

int main(void)
{
	setbuf(stdout, NULL);

	/*//Cuando se declara, pnumero apunta hacia basura,
	int *pnumero;
	//Si hacemos que apunte a direccion NULL y mostramos por printf lo que aloja ese puntero, veremos 0.
	pnumero = NULL;
	printf("%d", pnumero);

	//declaramos un numero (22) y le asigamos al puntero la direccion de este numero, luego usando el operador de indireccion * accedemos al valor alojado en la direccion de  memoria a la que "apunta" el puntero
	int numero = 22;
	pnumero = &numero;
	*pnumero = 31;

	printeamos el valor que aloja la direccion, si usaramos el ampersand & operador de direccion, mostrariamos la direccion de memoria que apunta el puntero ej: 0666821 ox124
	printf("\n%d", *pnumero);
	*/

	//memoria dinamica
	//malloc- memory allocation
	/*int* pLista;
	int i;

	pLista = (int*)malloc(sizeof(int)*2);
	printf("direccion malloc: %d",pLista);
	if(pLista != NULL)
	{
		for(i=0;i<2;i++)
		{
			 *(pLista+i) = i;
		}
	}

	for(i=0;i<2;i++)
	{
		printf("\n%d", *(pLista+i));
	}

	int* pAux;

	pAux = (int*)realloc(pLista, sizeof(int)*4);

	printf("\ndireccion realloc: %d",pAux);
	if(pAux != NULL){
		pLista = pAux;
	}

	for(i=0;i<4;i++)
	{
		 *(pLista+i) = i;
	}


	for(i=0;i<4;i++)
	{
		printf("\n%d", *(pLista+i));
	}


	free(pLista);*/

	eAlumno* pAlumno;
	eAlumno* listaPAlumno[10];

	pAlumno = new_Alumno();
	listaPAlumno[0] = pAlumno;

	printf("%d",listaPAlumno[0]->idAlumno);


	return EXIT_SUCCESS;
}

//CONSTRUCTOR DE ENTIDAD ALUMNO, DEVUELVE UN PUNTERO A UN ELEMENTO DE ALUMNO CON SUS CAMPOS INICIALIZADOS CON DETERMINADO VALOR
eAlumno* new_Alumno(void)   //por ahora void
{
	eAlumno* pAlumno;

	 pAlumno = (eAlumno*)malloc(sizeof(eAlumno)*1);
	 if(pAlumno != NULL)
	 {
		 strcpy(pAlumno->apellido,"\0");
		 strcpy(pAlumno->nombre,"\0");
		 pAlumno->idAlumno = 0;

		 return pAlumno;
	 }
	 else {
		 return NULL;
	 }

}

int initArrayPunteros(eAlumno* arrayP[], int lenElementos)
{
	int rtn;
	rtn = -1;






}
