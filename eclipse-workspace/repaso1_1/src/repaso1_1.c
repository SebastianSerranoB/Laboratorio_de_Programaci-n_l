/*
 ============================================================================
 Name        : repaso1-1.c
 Author      : SEBASTIAN SERRANO
 DIVISION    : K

 Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
El promedio de los números positivos.
El promedio de los números negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	char respuesta;

	int numeroIngresado;
	int acumuladorPositivos;
	int acumuladorNegativos;
	int contadorPositivos;
	int contadorNegativos;

	float promedioPositivos;
	float promedioNegativos;


	acumuladorPositivos = 0;
	acumuladorNegativos = 0;
	contadorPositivos = 0;
	contadorNegativos = 0;

	respuesta = 's';
	while(respuesta == 's')
	{
		printf("\nIngrese un numero entero: "); //Aca agregue '\n'
		scanf("%d", &numeroIngresado);
		if(numeroIngresado == 0)
		{
			printf("\nIngrese un numero entero distinto de 0: "); // '\n'
			scanf("%d", &numeroIngresado);
		}
		else
		{
			if(numeroIngresado > 0)
			{
				acumuladorPositivos = acumuladorPositivos + numeroIngresado;
				contadorPositivos++;
			}
			else
			{
				acumuladorNegativos = acumuladorNegativos + numeroIngresado;
				contadorNegativos++;
			}
		}


		printf("\n¿Desea ingresar otro numero? (s / n): "); //Aca le cambie el orden, para que despues de los ':' haya un espacio,
		                                                    // para que el usuario tenga espacio para escribir

		fflush(stdin);   //Y aca cambie el flush, no se porque no te funcionaba    / setbuf(stdin); puso nathan , pero el fflush funca igual no se que pasa

		scanf("%c", &respuesta);
	}

    //A todos los printf le aguregue '\n'
	if(contadorPositivos > 0)
	{
		promedioPositivos = (float)acumuladorPositivos / contadorPositivos;  //el (float)variable ES LO QUE SE LLAMA "CAST" "CASTEAR", HACEMOS QUE EL RETORNO DE ESA VARIABLE SEA FLOAT EN ESTA INSTANCIA. //PARSEAR O CASTEAR? PARSEAR ES DE STRING A NUMERO , CASTEAR DE NUMERO A NUMERO. HACE LO MISMO CON DISTINTO TIPO DE DATO
		printf("\nEl promedio de numeros positivos es: %.2f ", promedioPositivos); //el "%.2f" es el to.fixed , 2 seria, 2 decimales, si le pones uno , va a tomar solo un decimal, es decir, numero a la derecha de la coma
	}
	else
	{
		printf("\nNo se ingresaron numeros positivos.");
	}

	if(contadorNegativos > 0)
	{
		promedioNegativos = (float)acumuladorNegativos / contadorNegativos;  //el (float)variable ES LO QUE SE LLAMA "CAST" "CASTEAR", HACEMOS QUE EL RETORNO DE ESA VARIABLE SEA FLOAT EN ESTA INSTANCIA.
		printf("\nEl promedio de negativos es: %.2f", promedioNegativos);
	}
	else
	{
		printf("\nNo se ingresaron numeros negativos.");
	}


	return 0;
}

