/*
 ============================================================================
 Name        : burbujeoeInsercion.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{	setbuf(stdout, NULL);
    int i;
    int j;
    int aux;
    int numeros[5] = {6,5,9,1,3};

    printf("Muestro antes de ordenar\n");

    for(i=0;i<5;i++)
    {
        printf("\n%d",numeros[i]);
    }

    //BURBUJEO
    for(i=0;i<5-1;i++)//FOR PRINCIPAL
    {
        for(j=i+1;j<5;j++)//FOR SECUNDARIO
        {
            if(numeros[i]>numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];//Swap
                numeros[j] = aux;
            }
        }
    }

    //METODO INSERCIÓN
    for(i=1;i<5;i++)
    {
        aux = numeros[i];
        j = i - 1;

        while(j > -1 && aux < numeros[j])
        {
            numeros[j+1] = numeros[j];
            j--;
        }

        numeros[j+1] = aux;
    }

    printf("\nMuestro el array ordenado");

    for(i=0;i<5;i++)
    {
        printf("\n%d",numeros[i]);
    }
    return 0;
}

