/*
 ============================================================================
 Name        : memoriaDinamicaOtrosApuntes.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : constructores.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char nombre[20];
	char apellido[20];
	int dni;

}eAlumno;

//constructor

eAlumno * newAlumno();//constructor por defecto
eAlumno * newAlumnoParam(char * nombre,char * apellido,int dni);//constructor con parametros
int setDni(eAlumno * this,int dni);
//int getDni(eAlumno * this ,int * dni);1 forma
int getDni(eAlumno * this);

int setNombre(eAlumno* this, char nombre[]);
char* getNombre(eAlumno* this);

int setApellido(eAlumno* this, char apellido[]);
char* getApellido(eAlumno* this);

//completar get y set restantes

int main(void)
{
	setbuf(stdout, NULL);

	eAlumno * pAlumno;
	//int dni;




	//pAlumno = newAlumno();

	pAlumno = newAlumnoParam("matias","quiroz",6000);

	//getDni(pAlumno,&dni);




	if(pAlumno != NULL)
	{
		printf("%s -- %s -- %d",getNombre(pAlumno),getApellido(pAlumno),getDni(pAlumno));//pasar a una funcion

	}


	else
	{
		printf("error, no se encontro memoria,por favor intente de nuevo!!!");
	}

	if(pAlumno != NULL)
	{
		free(pAlumno);
	}


	return EXIT_SUCCESS;
}


eAlumno * newAlumno()
{
	 eAlumno * puntero;


	 puntero =  (eAlumno*)malloc(sizeof(eAlumno));

	 if(puntero !=NULL)
	 {
		strcpy( puntero->apellido  ," ");
		strcpy( puntero->nombre ," ");
		puntero->dni = 0;
	 }




	return puntero;

}


eAlumno * newAlumnoParam(char * nombre,char * apellido,int dni)
{
	eAlumno *  alumno = newAlumno();


	if(nombre != NULL && apellido !=NULL && alumno != NULL)
	{
		if(setDni(alumno,dni) == -1 || setApellido(alumno, apellido) -1 || setNombre(alumno, nombre) == -1)
		{
			free(alumno);
		}
	}


	return alumno;
}


int setDni(eAlumno * this, int dni)
{
	int retorno = -1;

	if(dni > 5000 && this != NULL)
	{
		this->dni = dni;
		retorno = 0;
	}

	return retorno;
}

/*int getDni(eAlumno * this ,int * dni)
{
	int retorno = -1;

	if(this!= NULL && dni != NULL)
	{

		*dni = this->dni;
		retorno = 0;

	}



	return retorno;
}
*/
int getDni(eAlumno * this)
{
	int retorno =-1;

	if(this!= NULL)
	{
		retorno =  this->dni;
	}

	return retorno;
}

int setNombre(eAlumno* this, char nombre[])
{
	int rtn;
	rtn = -1;

	if(this != NULL && strlen(nombre) > 1){
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

char* getNombre(eAlumno* this)
{
	//malloc que pasa con esta direccion?
	char auxiliar[1024];
	if(this != NULL)
	{
		strcpy(auxiliar, this->nombre);
	}

	return auxiliar;
}



int setApellido(eAlumno* this, char apellido[])
{
	int rtn;
	rtn = -1;

	if(this != NULL && strlen(apellido) > 1){
		strcpy(this->nombre, apellido);
		rtn = 0;
	}

	return rtn;
}
char* getApellido(eAlumno* this)
{
	//malloc que pasa con esta direccion?
	char auxiliar[50];
	if(this != NULL)
	{
		strcpy(auxiliar,this->apellido);
	}

	return auxiliar;
}

