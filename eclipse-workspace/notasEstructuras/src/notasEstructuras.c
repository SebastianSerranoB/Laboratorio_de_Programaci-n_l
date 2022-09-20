/*
 ============================================================================
 Name        : notasEstructuras.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*#include <stdio.h>
#include <stdlib.h>
#define LENGHT 5

void mostrarArrays(int[], char[], int);
void ordenarArrays(int[], char[], int);
int main(void)
{
	setbuf(stdout,NULL);

	char sexos[LENGHT] = {'f','m','f','m','f'};
	int edades[LENGHT] = {6,4,3,5,7};
	//funcion con un solo tamaño del array
	//ordenar el array //metodos/algoritmos burbujeo, insercion, etc
	mostrarArrays(edades, sexos, LENGHT);
	//void ordenarArrays(int, char, LENGHT);



	return EXIT_SUCCESS;
}


void mostrarArrays(int edad[], char sexo[], int lenght)
{
	int i;
	for(i=0;i<lenght;i++)
	{
		printf("\n-Edad: %d", edad[i]);
		printf("  -Sexo: %c", sexo[i]);
	}
}
void ordenarArrays(int edades[], char sexo[], int lenght)
{


}


/*
 * #include <stdio.h>
#include <stdlib.h>

void main(void){

    char s[5]={'A', 'B', 'C', 'D', 'E'};
    int e[5]={6, 4, 3, 5, 7,};
    int i, j;

    for(i=0;i<5-1;i++){
        for(j=i+1;j<5;j++){
            if(e[i]>e[j]){

                ////// ORDENO EDADES.

                int a=e[i];
                e[i]=e[j];
                e[j]=a;

                ////// ORDENO SEXOS.

                char b=s[i];
                s[i]=s[j];
                s[j]=b;

            }
        }
    }

    for(i=0;i<5;i++){
        printf("\t[ %d ]",e[i]);
    }

    printf("\n");

    for(i=0;i<5;i++){
        printf("\t[ %c ]",s[i]);
    }

} /// FIN MAIN.
  */
 */

 typedef struct
 {
	char nombre[20];
	char apellido[20];
	int nota;


 }eAlumno

 eAlumno vectorAlumnos[10];
