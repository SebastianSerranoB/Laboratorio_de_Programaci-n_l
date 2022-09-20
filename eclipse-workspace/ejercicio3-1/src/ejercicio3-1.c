/*
 ============================================================================
 Name        : ejercicio3-1.c
 Author      : SERRANO SEBASTIAN
 Division	 : k1
 Ejercicio 3-1:
Crear una función que muestre por pantalla el número flotante que recibe como parámetro.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//firmo, declaro funcion
float mostrarFlotante(float a);

int main(void)
{
	setbuf(stdout, NULL);
	//declaro variable local
	float numero;

	//le asigno un valor
	numero = 5.22;

	//llamo a la funcion enviandole como parametro la var numero
	mostrarFlotante(numero); // en esta instancia, el parametro es formal,(esta siendo asignado pero no utilizado/reemplazado)


 return EXIT_SUCCESS;
}

//cuerpo, desarrolo de la funcion
float mostrarFlotante(float a) // cuando esta funcion corre el parametro es activo ya que recibio el valor y lo reemplazo.....
{

	printf("el numero es: %3.2f",a);  //imprimo el valor de la variable tipo float "a",quien recibio el valor de el parametro(variable) "numero"
	//no devuelve nada, el compilador me da un warning
}
