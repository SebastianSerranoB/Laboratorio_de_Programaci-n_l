/*
 ============================================================================
 Name        : ejercicio6-3aux.c
 Author      : Serrano Belloso Sebastian
 Division     : K-1

 Ejercicio 6-3:
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el
apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:

Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //contiene constantes y tipos como NULL, size_t. Funciones como : strcat,strcpy,strcmp,strlcmp,strlen,gets;

#include <ctype.h>    //contiene funciones como tolower y toupper
						/*En el lenguaje de programación C las variables del tipo Tipo de dato carácter(char) almacenan el código ASCII del carácter (deben de estar dentro del rango 0-255 o 00-FF en hexadecimal).
						Simplemente lo que hace tolower() es sumarle 32 al número entero correspondiente al código ASCII del carácter.^, en el caso de toupper restariamos 32(wikipedia)*/

int main(void)
{
	setbuf(stdout, NULL);

	char nombreIngresado[22];
	char apellidoIngresado[22];
	char nombreCompleto[45];       //deberia ser Gomez Fernandez, Juan Carlos
	int lenght;
	int i;

	printf("\nIngrese el nombre: "); // jUAn caRlOs ingresaremos como ejemplo
	fflush(stdin);
	gets(nombreIngresado);                   //FUNCION GETS() [getString]; se encarga de leer y almacenar una cadena de caracteres introducida mediante el teclado.
											 //La variable es guardada hasta que haya un salto de línea (“\n”), sin embargo, el salto de línea NO se guarda.
											 //	La función gets en C automáticamente agrega un carácter de terminación NULL (“\0”); además es capaz de guardar cualquier tipo de caracter,
											 //incluido los espacios en blanco y no tiene ninguna limitante en cuanto al tamaño de la cadena de caracter que se introduce.

	printf("\nIngrese el apellido: ");  //gOMeZ fernANDeZ,
	fflush(stdin);
	gets(apellidoIngresado);



	//COPIAMOS Y CONCATENAMOS
	strcpy(nombreCompleto, apellidoIngresado);//gOMeZ fernANDeZ           //strcpy (destino, origen) , funcion que copia el contendio desde un origen a un destino
																		  //El puntero destino debe contener suficiente espacio para copiar sobre la zona de memoria a la que apunta, la cadena apuntada por origen
	strcat(nombreCompleto,", ");//gOMeZ fernANDeZ,     //strcat concatena cadenas de caracteres [stringConcatenate]
	strcat(nombreCompleto, nombreIngresado);//gOMeZ fernANDeZ, jUAn caRlOs


	//FORMATEAMOS
	strlwr(nombreCompleto);       //como el toLowerCase de JS, lleva a minusculas la cadena de caracteres.

	 lenght = strlen(nombreCompleto);// The strlen() function takes a string as an argument and returns its length. The returned value is of type size_t (the unsigned integer type).

	 if(lenght > 0)   //si la longitud de la cadena es mayor a cero
	 {
		for(i=0;i<lenght;i++)  //for que recorre la longitud de la cadena
		{
			if(nombreCompleto[i-1] == ' ' || i == 0)  //" " o 32 se denomina el espacio ..... if; si en i menos uno existe un espacio, i  es con inicial en mayuscula ya que sera el nombre o el apellido, o si i es 0, es decir la primer letra ingresada
			{
				nombreCompleto[i] = toupper(nombreCompleto[i]); //La función toupper() toma un carácter y devuelve su versión en mayúscula (si es que existe).
																//Cuando el carácter no tiene versión en mayúscula, entonces se devuelve el argumento sin modificaciones
			}													//si i - 1 es un espacio; i entonces sera mayuscula
		}
	  }


	 //MOSTRAMOS
	 printf("\nEl nombre completo es %s", nombreCompleto);

	return EXIT_SUCCESS;
}
