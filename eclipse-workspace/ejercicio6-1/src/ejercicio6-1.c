/*
 ============================================================================
 Name        : ejercicio6-1.c
 Author      : Serrano Belloso Sebastian
 Division   : K-1
 Ejercicio 6-1:
Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio
de valores de dichas variables.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT 5

int main(void)
{
	setbuf(stdout, NULL);
	int i;

	int a[CANT] = {3,10,8,9,1};
	int b[CANT] = {22,11,15,54,12};


	for(i=0;i<CANT;i++)
	{
		 b[i] = a[i];
	}

	for(i=0;i<CANT;i++)
	{
		printf("\nPara el indice %d, a es %d y b es %d",i,a[i],b[i]);
	}

	return EXIT_SUCCESS;
}










/*void bubbleSort (int a[],int len)
{
int j, aux;
int flagNoEstaOrdenado = 1;
while (flagNoEstaOrdenado==1)
{
flagNoEstaOrdenado = 0;
for (j = 1; j < len; j++)
{
if (a[j] < a[j - 1])
{
aux = a[j];
a[j] = a[j - 1];
a[j - 1] = aux;
flagNoEstaOrdenado = 1;
}
}
}
}*/
