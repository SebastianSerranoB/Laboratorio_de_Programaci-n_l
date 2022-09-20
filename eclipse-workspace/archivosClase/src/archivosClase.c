/*
 ============================================================================
 Name        : archivosClase.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	setbuf(stdout, NULL);
	return EXIT_SUCCESS;
}

/*
 Antes, todo dato que cargabamos en un programa se perdia luego de que este finalizara, ahora con ARCHIVOS, vamos a poder guardar esos datos en un archivo de texto o un archivo binario
-En el tp usamos archivsos de texto tipo csv, esta guardada en binario pero interpretada como texto
BINARIO
el binario guarda directamente un char, un int, una struct, con su peso correspondiente en bytes
TEXTO
El texto nos muestra guardado como texto todo variable



La idea de trabajar con funciones los archivos, seria enviarl epor parametreo el NOMBRE del archivo, y crear el punteor archivo dentro de la funcion, operar y cerrarlo ahi mismo, no es recomendable hacer un doble puntero a funcion para enviar
ese file como parametro, es muy engorroso

Parsear es la manera(formato definido por el programador) en la que el programa va a leer e interpretar un archivo de texto o binario.
el FALSO SCANEO es para corroborar la primer linea de texto ya que suele ser el titulo, esa la evadimos y leemos el resto
    */
