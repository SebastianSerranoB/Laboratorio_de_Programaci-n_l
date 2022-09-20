/*
 ============================================================================
 Name        : masNotasEstructuras.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 3

typedef struct {
	char nombre[20];
	int nota;
}ePersona;

int main(void){
	ePersona pers[CANT], aux;
	int auxNota;
	char auxNombre[20];
	int i, j;

	for( i=0; i<CANT; i++){
		printf("Nombre: ");
		fflush(stdin);
		scanf("%s", pers[i].nombre);

		printf("Nota: ");
		scanf("%d", &pers[i].nota);
	}

	for( i=0; i<CANT-1; i++ )
		for( j=i+1; j<CANT; j++ )
			if( ( strcmp(pers[i].nombre, pers[j].nombre ) ) > 0 ){

				//auxNota = pers[i].nota;
				//pers[i].nota = pers[j].nota;
				//pers[j].nota = auxNota;

				//strcpy( auxNombre, pers[i].nombre );
				//strcpy( pers[i].nombre, pers[j].nombre );
				//strcpy( pers[j].nombre, auxNombre );

				aux = pers[i];
				pers[i] = pers[j];
				pers[j] = aux;
			}

	for( i=0; i<CANT; i++){
		printf("%s\t\t%d\n", pers[i].nombre, pers[i].nota);
	}

	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>

#define CANT 3

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	char nombre[31];
	int nota;
	char asignatura[31];
	eFecha fechaNacimiento;
}eAlumno;

int main(void){
	eAlumno alu1, alu2;

	printf("Nombre: ");
	fflush(stdin);
	scanf("%s", alu1.nombre);

	printf("Asignatura: ");
	fflush(stdin);
	scanf("%s", alu1.asignatura);

	printf("Nota: ");
	scanf("%d", &alu1.nota);

	printf("Dia: ");
	scanf("%d", &alu1.fechaNacimiento.dia);

	printf("Mes: ");
	scanf("%d", &alu1.fechaNacimiento.mes);

	printf("A%cio: ", 164);
	scanf("%d", &alu1.fechaNacimiento.anio);

	alu2 = alu1;

	//strcpy( alu2.nombre, alu1.nombre ); //Ok
	//strcpy( alu2.asignatura, alu1.asignatura ); //Ok
	//alu2.nota = alu1.nota; //Ok

	printf("%s\t\t%s\t\t%d\t\t%d-%d-%d", alu2.nombre, alu2.asignatura, alu2.nota, alu2.fechaNacimiento.dia, alu2.fechaNacimiento.mes, alu2.fechaNacimiento.anio);

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#define CANT 3

typedef struct{
	char nombre[31];
	int nota;
}eAlumno;

int main(void){
	int i;
	eAlumno alu[CANT];

	for(i=0;i<CANT;i++){
		printf("Ingrese nombre: ");
		fflush(stdin);
		scanf("%s", alu[i].nombre);

		printf("Ingrese nota: ");
		scanf("%d", &alu[i].nota);

	}

	printf("Nombre\t\tNota");
	printf("\n------------------------------------------");
	for(i=0;i<CANT;i++){
		printf("\n%s\t\t%d", alu[i].nombre, alu[i].nota);
	}

	return 0;
}
*/


/*

struct eAlumno{
	int legajo;
	char nombre[31];
	char carrera[31];
};

struct eAlumno alumno;

typedef struct{
	int legajo;
	char nombre[31];
	char carrera[31];
}eAlumno;

eAlumno alumno;
eAlumno alumnos[5];

alumno.legajo = 101;
alumnos[indice].legajo = 102;

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nombre[20];
	int nota;
}ePersona;

typedef struct {
	char nombre[20];
	int nota;
}ePersona2;

int main(void){
	ePersona per;
	ePersona2 per2;

	printf("Nombre: ");
	fflush(stdin);
	scanf("%s", per.nombre);

	printf("Nota: ");
	scanf("%d", &per.nota);

	//per2 = per;

	printf("%s\t\t%d\n", per2.nombre, per2.nota);

	return 0;
}

