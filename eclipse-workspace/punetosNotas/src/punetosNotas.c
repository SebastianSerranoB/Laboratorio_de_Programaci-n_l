/*
 ============================================================================
 Name        : punetosNotas.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */




//(*puntero).nota = 22;     primero accede al puntero, luego al valor que tien esa variable, en este caso puntero tiene la dir  de una estructura
//*puntero->nota == 22:    la otra forma

/*
 ============================================================================
 Name        : punteros.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
	setbuf(stdout, NULL);
    EPersona per;
	EPersona *ptrPer;
	EPersona pers[2];
	EPersona *ptrPers;
    int i;

    ptrPer = &per;

    ptrPers = pers;

  /*  printf("\n\nESTRUCTURA SIMPLE:");

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", per.nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", ptrPer->nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);

    //

     */
    printf("\n\nPUNTERO A ARRAY DE ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(ptrPers+i)->dni);

        printf("\nNOMBRE: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", (*(ptrPers+i)).nombre);

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.dia);

        printf("\nMES: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.mes);

        printf("\nAÑO: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.anio);
    }


   // ptrPers->fechaNac.dia =12;
    for(i=0; i<2; i++){
        /* printf("%s - %ld - %d/%d/%d", (*(ptrPers+i)).nombre, (*(ptrPers+i)).dni, (*(ptrPers+i)).fechaNac.dia, (*(ptrPers+i)).fechaNac.mes, (*(ptrPers+i)).fechaNac.anio); */

        printf("%s - %ld - %d/%d/%d", (ptrPers+i)->nombre, (ptrPers+i)->dni, (ptrPers+i)->fechaNac.dia, (ptrPers+i)->fechaNac.mes, (ptrPers+i)->fechaNac.anio);
    }



    return 0;
}
// x151

