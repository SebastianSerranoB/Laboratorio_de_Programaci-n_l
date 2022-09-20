/*
 ============================================================================
 Name        : ejercicio1-3.c
 Author      : SEBASTIAN SERRANO
 DIVISION    : K

 Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay numero del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int numeroTres;
	//nueva variable
	int numeroMedio;

	//input
	printf("Ingrese el primer numero: ");
	scanf("%d",&numeroUno);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);
	printf("Ingrese el tercer numero: ");
	scanf("%d",&numeroTres);


	//proceso y output
	//v1
	/*if((numeroUno > numeroDos && numeroUno < numeroTres)|| (numeroUno > numeroTres && numeroUno < numeroDos))
	{
		printf("El numero del medio es: %d",numeroUno);
	}
	else
	{
		if((numeroDos > numeroUno && numeroDos < numeroTres) ||( numeroDos > numeroTres && numeroDos < numeroUno))
		{
			printf("El numero del medio es: %d",numeroDos);
		}
		else
		{
			if((numeroTres > numeroUno && numeroTres < numeroDos) || (numeroTres > numeroDos && numeroTres < numeroUno))
			{
				printf("El numero del medio es: %d",numeroTres);
			}
			else
			{
				printf("No existe numero del medio.");
			}
		}
	}		*/

	//v1.1
	if(numeroUno != numeroDos && numeroUno != numeroTres && numeroDos != numeroTres)
	{
		if((numeroUno > numeroDos && numeroUno < numeroTres)|| (numeroUno > numeroTres && numeroUno < numeroDos))
		{
			numeroMedio = numeroUno;
		}
		else
		{
			if((numeroDos > numeroUno && numeroDos < numeroTres) ||( numeroDos > numeroTres && numeroDos< numeroUno))   // parentesis lo hace mas legible al diferenciar porciones de codigo y aseguramos que corra bien, el operador && tiene una jerarquia mas importante que el ||
			{
				numeroMedio = numeroDos;
			}
			else
			{
				numeroMedio = numeroTres;
			}
		}

		printf("El numero del medio es: %d",numeroMedio);
	}
	else
	{
		printf("No existe un numero del medio.");
	}



	return 0;
}


//otra forma de resolverlo
