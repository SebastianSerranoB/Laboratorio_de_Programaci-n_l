/*
 ============================================================================
 Name        : ejercicio2-1.c
 Author      : SEBASTIAN SERRANO
 Division	 : K1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numeroIngresado;
	int acumuladorNumeros;
	int contador;
	int promedio;

	acumuladorNumeros = 0;
	contador = 0;


	/*printf("Ingrese el primer numero: ");
	scanf("%d",&numeroUno);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);
	printf("Ingrese el tercer numero: ");
	scanf("%d",&numeroTres);
	printf("Ingrese el cuarto numero: ");
	scanf("%d",&numeroCuatro);
	printf("Ingrese el quinto numero: ");
	scanf("%d",&numeroCinco);*/

	while(contador<5)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numeroIngresado);

		acumuladorNumeros = acumuladorNumeros + numeroIngresado;
		contador++;
	}

	promedio = acumuladorNumeros / contador;
	printf("El promedio del total es: %d",promedio);



	return EXIT_SUCCESS;
}
