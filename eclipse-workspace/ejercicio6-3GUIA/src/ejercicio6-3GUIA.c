/******************************************************************************

Ejercicio 6-3:
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio

nombre-> gOmEZ feRNaNanDez
apellido-> jUAN caRlOs
nombreCompleto -> Gomez Fernandez, Juan Carlos

Mariano Fernández

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int FormatearCadena(char []);
int RetornarNombreCompleto(char [], char [], char []);
int GetString (char [],char []);

int main()
{
    setbuf(stdout, NULL);
    char nombre[50];
    char apellido[50];
    char nombreCompleto[100];

    GetString("Ingrese un nombre: ",nombre);
    GetString("\nIngrese un apellido: ",apellido);

    RetornarNombreCompleto(nombre,apellido,nombreCompleto);//gOMeZ fernANDeZ, jUAn caRlOs
    FormatearCadena(nombreCompleto);//Formatea la cadena por ende
        								//gOMeZ fernANDeZ, jUAn caRlOs => Gomez Fernandez, Juan Carlos

    printf("Su nombre completo es %s",nombreCompleto);

    return 0;
}

int GetString (char mensaje[],char cadena[])
{
    int retorno=0;

    if(mensaje != NULL && cadena != NULL)
    {
        fflush(stdin);
        printf("\n%s", mensaje);
	    scanf("%[^\n]", cadena);
	    retorno=1;
    }

    return retorno;
}

int RetornarNombreCompleto(char nombre[], char apellido[],char nombreCompleto[])
{
    int retorno=0;

    //Nombre=gErMaN

    if(nombre != NULL && apellido != NULL)
    {
        strcpy(nombreCompleto,apellido);//gOMeZ fernANDeZ
        strcat(nombreCompleto,", ");//gOMeZ fernANDeZ,
        strcat(nombreCompleto, nombre);//gOMeZ fernANDeZ, jUAn caRlOs

        retorno=1;
    }

    return retorno;
}

int FormatearCadena(char cadena[])
{
   int retorno=0;
   int tam;
   int i;

   tam=strlen(cadena);//gOMeZ fernANDeZ, jUAn caRlOs
   strlwr(cadena);//gomez fernandez, juan carlos

   if(cadena != NULL)
   {
       for(i=0;i<tam;i++)
       {
           if(cadena[i-1] == " " || i == 0)//" " o 32 se denomina el espacio
           {
               cadena[i] = toupper(cadena[i]);
           }
       }
       retorno=1;
   }

   return retorno;
}
