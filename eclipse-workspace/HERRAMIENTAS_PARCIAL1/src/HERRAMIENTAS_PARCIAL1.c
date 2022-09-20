/*
 ============================================================================
 Name        : HERRAMIENTAS_PARCIAL1.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1

 Funciones basicas y de ABM, validaciones, defines, estructuras orientadas a un ABM GENERICO PARA EL PARCIAL UNO.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
	setbuf(stdout, NULL);


	return EXIT_SUCCESS;
}

//ABM
//INICIALIZAR ARRAY

//HARDCODEAR STRUCTS
void hardcodearDatosEmpleados(sEmpleados lista[], int tam)
{

	//int legajos[] = {1,8,7,6,}; //aca declaramos el legajo[] sin tamaño por el momento pero lo igualamos a 1,2,3,4 eso define el tamaño de mi array (4) y termina la instruccion
	//int legajos[];  //Esto es incorrecto, no le indicamos tamaño al array y terminamos la instruccion
	//CUAL ES LA DIFERENCIA? ATENCION:
}



//alta empleado
//void alta(struct array[], tamanio);
//buscarlibre();



//BUSCAR LIBRE
//esta funcion la llamarias en el alta(), no en el main, que retorne el indice libre para cargar el alta
/* int buscarLibre(struct array[], tamanio);
{
	int i;
	int index = -1;    //indice imposible de un array,

	for(i=0;i<tamanio; i++)
	{
		if(array[i].estado == LIBRE)
		{
			index = i:
					break; //si encuentro el libre rompro el for

		}
	}

	return index;
}

(alta)
indice = buscarLibre(lista[], EMPLEADOS);
IF(indice != -1){
alta()
}
else
{
no hay espacio
}

//GENERICAS, GETTERS

 int getInt(int min, int max)
 {
 	 int integer;

 	 scanf("%d", &integer);
 	 while(integer < min || integer > max)
 	 {
 	 	 printf("\nError, re-enter an integer(> %d && < %d).",min, max);
 	 	 scanf("%d", &integer);
 	 }

 	 return integer;
 }


 */





















































/**/
