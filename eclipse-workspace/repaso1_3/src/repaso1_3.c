/*
 ============================================================================
 Name        : repaso1_3.c
 Author      : SERRANO SEBASTIAN
 Division    : K-1

 Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	//ingreso de datos
	char respuesta, sexoIngresado, cursadaIngresada;
	int legajoIngresado, cantidadDeMaterias, notaPromedio, edadIngresada;
	//para informar
	int contadorFemenino = 0, mejorPromedioFemenino, legajoMejorPromedioFemenino;
	int menorEdadMasculinoYLibre, contadorMasculinoYLibre = 0, legajoMasculinoYLibre;
	float promedioFemenino, promedioMasculino, promedioNoBinario;
	int contadorMasculino = 0, contadorNoBinario = 0;
	int acumuladorPromedioFemenino = 0, acumuladorPromedioMasculino = 0, acumuladorPromedioNoBinario = 0;
	int banderaMasMaterias = 0, edadMasMaterias, legajoMasMaterias, cursaMasMaterias; //como paso edad y legajo a un printf en una sola variable que contenga el mensaje?


	do
	{
		//********INGRESO Y VERIFICACION DE DATOS**********
		printf("Ingrese el numero de legajo: \n");
		scanf("%d", &legajoIngresado);
		while(legajoIngresado < 1)
		{
			printf("Error, reingrese el legajo: \n");
			scanf("%d", &legajoIngresado);
		}

		printf("Ingrese modelo de cursada: \n");
		fflush(stdin);
		scanf("%c", &cursadaIngresada);
		while(cursadaIngresada != 'L' && cursadaIngresada != 'P' && cursadaIngresada != 'R')
		{
			printf("Error, reingrese el modelo: L, P O R\n");
			fflush(stdin);
			scanf("%c", &cursadaIngresada);
		}

		printf("Ingrese la cantidad de materias: \n");
		scanf("%d", &cantidadDeMaterias);
		while(cantidadDeMaterias < 1 || cantidadDeMaterias > 8)
		{
			printf("Error, reingrese la cantidad de materias: > 0 && < 9\n");
			scanf("%d", &cantidadDeMaterias);
		}

		printf("Ingrese el sexo del alumno: \n");
		fflush(stdin);
		scanf("%c", &sexoIngresado);
		while(sexoIngresado != 'F' && sexoIngresado != 'M' && sexoIngresado != 'O')
		{
			printf("Error, reingrese el sexo del alumno: F, M U O \n");
			fflush(stdin);
			scanf("%c", &sexoIngresado);
		}

		printf("Ingrese el promedio de notas: \n");
		scanf("%d", &notaPromedio);
		while(notaPromedio < 0 || notaPromedio > 10)
		{
			printf("Error, reingrese el promedio de notas: \n");
			scanf("%d", &notaPromedio);
		}

		printf("Ingrese la edad del alumno: \n");
		scanf("%d", &edadIngresada);
		while(edadIngresada < 17 || edadIngresada > 150)
		{
			printf("Error, reingrese la edad del alumno: \n");
			scanf("%d", &edadIngresada);
		}

		//********ALGORITMOS PARA INFORMAR*********

		//a) El Legajo del mejor promedio femenino.


		//b) El legajo del más joven de los alumnos masculinos entre los que dan libre.



		//c) El promedio de nota por sexo.
		if(sexoIngresado == 'M')
		{
			contadorMasculino++;
			acumuladorPromedioMasculino += notaPromedio;
			if(cursadaIngresada == 'L' )
			{
				if(edadIngresada < menorEdadMasculinoYLibre   || contadorMasculinoYLibre == 0)
				{
					menorEdadMasculinoYLibre = edadIngresada;
					legajoMasculinoYLibre = legajoIngresado;
				}

				contadorMasculinoYLibre++;
			}

		}
		else
		{
			if(sexoIngresado == 'F')
			{
				if(notaPromedio > mejorPromedioFemenino || contadorFemenino == 0)
				{
					mejorPromedioFemenino = notaPromedio;
					legajoMejorPromedioFemenino = legajoIngresado;
				}

				acumuladorPromedioFemenino += notaPromedio;
				contadorFemenino++;
			}
			else
			{

				contadorNoBinario++;
				acumuladorPromedioNoBinario += notaPromedio;
			}
		}

		//d) La edad y legajo del que cursa más materias. (Sin importar su género)
		if(cantidadDeMaterias > cursaMasMaterias || banderaMasMaterias == 0)
		{
			edadMasMaterias = edadIngresada;
			legajoMasMaterias = legajoIngresado;
			cursaMasMaterias = cantidadDeMaterias;

			banderaMasMaterias = 1;
		}





		//*******ROMPO O CONTINUO EL WHILE********
		printf("\nDesea cargar los datos de otro alumno? s o n\n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta == 's');
	//*********FIN DEL WHILE, SIGUE EL MAIN**********


	//******INFORMO*******
	//a) El Legajo del mejor promedio femenino.
	if(contadorFemenino > 0)
	{
		printf("El legajo del mejor promedio femenino es: %d\n", legajoMejorPromedioFemenino);
	}
	else
	{
		printf("No se ingresaron alumnas.\n");
	}

	//b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
	if(contadorMasculinoYLibre > 0)
	{
		printf("El legajo del alumno mas joven y de modalidad libre es: %d\n", legajoMasculinoYLibre);
	}
	else
	{
		printf("No se ingresaron alumnos masculinos y con modalidad de cursada libre.\n");
	}

	//c) El promedio de nota por sexo.
	if(contadorFemenino > 0)
	{
		promedioFemenino = (float)acumuladorPromedioFemenino / contadorFemenino;
		printf("La nota promedio de %d alumnas es: %4.2f\n", contadorFemenino, promedioFemenino);
	}
	else
	{
		printf("No se ingresaron alumnas.\n");
	}

	if(contadorMasculino > 0)
	{
		promedioMasculino = (float)acumuladorPromedioMasculino / contadorMasculino;
		printf("La nota promedio de %d alumnos es: %4.2f\n", contadorMasculino, promedioMasculino);
	}
	else
	{
		printf("No se ingresaron alumnos masculinos.\n");
	}

	if(contadorNoBinario > 0)
	{
		promedioNoBinario = (float)acumuladorPromedioNoBinario / contadorNoBinario;
		printf("La nota promedio de %d alumnos no binarios es: %4.2f\n", contadorNoBinario, promedioNoBinario);
	}
	else
	{
		printf("No se ingresaron alumnos no binario.\n");
	}

	//d) La edad y legajo del que cursa más materias. (Sin importar su género)
	printf("La edad de el que cursa mas materias es %d y su legajo es %d\n", edadMasMaterias, legajoMasMaterias);



	return EXIT_SUCCESS;
}
