/*
 ============================================================================
 Name        : ejercicio6-3v1.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	/*
	Ejercicio 6-3:
	Pedirle al usuario su nombre y apellido
	(en variables separadas, una para el nombre y otra para el apellido).
	Ninguna de las dos variables se puede modificar.
	Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
	Por ejemplo:
	Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
	" Gomez, Juan Ignacio "
	*/
	// Gomez Perez
	//GomezPerez
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>

	int main(void){
		char nombre[31];
		char apellido[31];
		char apeNom[70];
		int i, longitud, contador;

		printf("Apellido: ");
		fflush(stdin);
		scanf("%[^\n]", apellido);

		printf("Nombre: ");
		fflush(stdin);
		scanf("%[^\n]", nombre);

		//Quitamos espacio en blanco al comienzo
		longitud = strlen( apellido );
		contador = 0;
		for( i=0; i<longitud; i++ ){
			if( apellido[i] == ' '){
				contador++;
			}
			else{
				break;
			}
		}

		//"- - G o m e z\0"
		//"G o m e z e z\0"
		// 0 1 2 3 4 5 6 7
		if( contador > 0 ){
			for( i=0; i<longitud-contador+1; i++ ){
				apellido[i] = apellido[i+contador];
			}
		}

		//"Gomez--\0"


		strlwr(apellido);
		strlwr(nombre);

		apellido[0] = toupper( apellido[0] );
		longitud = strlen(apellido);
		for( i=0; i<longitud; i++ ){
			if( apellido[i] == ' ' ){
				apellido[i+1] = toupper( apellido[i+1] );
			}
		}

		nombre[0] = toupper( nombre[0] );
		longitud = strlen(nombre);
		for( i=0; i<longitud; i++ ){
			if( nombre[i] == ' ' ){
				nombre[i+1] = toupper( nombre[i+1] );
			}
		}

		strcpy( apeNom, apellido );
		strcat( apeNom, ", " );
		strcat( apeNom, nombre );

		return 0;
	}

	return EXIT_SUCCESS;
}
/*
Ejercicio 6-3:
Pedirle al usuario su nombre y apellido
(en variables separadas, una para el nombre y otra para el apellido).
Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
" Gomez, Juan Ignacio "
*/
// Gomez Perez
//GomezPerez
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char nombre[31];
	char apellido[31];
	char apeNom[70];
	int i, longitud, contador;

	printf("Apellido: ");
	fflush(stdin);
	scanf("%[^\n]", apellido);

	printf("Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", nombre);

	//Quitamos espacio en blanco al comienzo
	longitud = strlen( apellido );
	contador = 0;
	for( i=0; i<longitud; i++ ){
		if( apellido[i] == ' '){
			contador++;
		}
		else{
			break;
		}
	}

	//"- - G o m e z\0"
	//"G o m e z e z\0"
	// 0 1 2 3 4 5 6 7
	if( contador > 0 ){
		for( i=0; i<longitud-contador+1; i++ ){
			apellido[i] = apellido[i+contador];
		}
	}

	//"Gomez--\0"


	strlwr(apellido);
	strlwr(nombre);

	apellido[0] = toupper( apellido[0] );
	longitud = strlen(apellido);
	for( i=0; i<longitud; i++ ){
		if( apellido[i] == ' ' ){
			apellido[i+1] = toupper( apellido[i+1] );
		}
	}

	nombre[0] = toupper( nombre[0] );
	longitud = strlen(nombre);
	for( i=0; i<longitud; i++ ){
		if( nombre[i] == ' ' ){
			nombre[i+1] = toupper( nombre[i+1] );
		}
	}

	strcpy( apeNom, apellido );
	strcat( apeNom, ", " );
	strcat( apeNom, nombre );

	return 0;
}

