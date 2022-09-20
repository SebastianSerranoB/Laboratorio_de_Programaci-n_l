/*
 ============================================================================
 Name        : Memoria_Dinamica.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : PunterosBase.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nombre[20];
	char apellido[20];
	int dni;

}eAlumno;


int main(void)
{
	setbuf(stdout, NULL);

	eAlumno * pAlumno;
	eAlumno *auxPAlumno;
	int i;
	auxPAlumno = NULL;






	pAlumno =(eAlumno*) malloc(sizeof(eAlumno)*5);

	 if(pAlumno != NULL)
	 {
		 printf("se reservo espacio en memoria\n");
		 for(i=0;i<5;i++)
		 {

			 (pAlumno+i)->dni = 25;

		 }

		 for(i=0;i<5;i++)
			{

				printf("%d\n",(pAlumno+i)->dni);

			}

	 }
	 else
	 {

		 printf("no pude reservar espacio en memoria");

	 }



	 /*pInt =(int*)calloc(5,sizeof(int));

	 if(pInt != NULL)
		 {
			 printf("se reservo espacio en memoria\n");

			 for(i=0;i<5;i++)
				{

					printf("%d\n",*(pInt+i));

				}

		 }
		 else
		 {

			 printf("no pude reservar espacio en memoria");

		 }

	  */





	 auxPAlumno  = (eAlumno*) realloc(pAlumno,sizeof(eAlumno)*10); // 14 bites , 40 bites


	 if(auxPAlumno!=NULL)
	 {
		 pAlumno = auxPAlumno;


		 for(i=0;i<10;i++)
		{

			printf("%d\n",(pAlumno+i)->dni);


		}
	 }


	 free(pAlumno);



	return EXIT_SUCCESS;
}
