/*
 ============================================================================
 Name        : ClasePunteros.c
 Author      : Serrano Belloso Sebastian

 PRIMER CLASE PUNTEROS
 De memoria estatica, a  memoria Dinamica
 ============================================================================
 */
/*
 ============================================================================
 NOTAS*********************

 PRIMER CLASE PUNTEROS
 Punteros o apuntadores
 -De memoria estatica, a  memoria Dinamica
- C tiene una gran potencia, nos permite agregar tantos elementos a memoria como sea necesario
 en tiempo de ejecucion.
 - Curva de aprendizaje puntero

-Puntero: es una variable que no aloja un dato o valor, sino que aloja una direccion de memoria
donde se puede encontrar un dato del tipo declarado.
-Declaracion:
char* a;
char *a;
Es valido de ambas maneras, pero debe estar pegado el asterisco o al tipo de dato o al nombre de la variable.

-Operadores del puntero : "*", "&".
 Operador de indireccion * ---> letra *p  accede directo al dato, no a la direccion
 Operador de direccion &
 variable > direccion > dato

 ** cuando declaramos una variable (cualquiera), el sistema le asigna un espacio en memoria, y ese espeacio tiene una direccion.
 **La direccion de memoria en la computadora es fisica, tiene que ver con el hardware.
 **La computadora no accede directamente al dato sino a la direccion de memoria.

 int* a ;
 a = 7 >>>> accedemos al dato que contiene a, que siempre va a ser  una dic.memoria 0x100(ejemplo), y en esa memoria asignariamos algo
 *a = &b, le asignamos la direccion de memoria de a

c = * a,  c accede a el dato que tiene (a) que es una direccion de memoria, esa direccion de memoria es la de la variable b que contiene 15



 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);


	return EXIT_SUCCESS;

}

/*
int nro;
char letra;
float salario;
char nombre[31];

nro => 5
letra => 'a'
salario => 25000.50
nombre => "Pedro"

Puntero
Es una variable

int* a;
char* p;
float* f;

int *a;
char *p;
float *f;

* Operador de indireccion
& Operador de direccion

scanf("%c", &letra);
&letra => 0X100
letra



scanf("%d", &nro);

MEMORIA
variable |direccion | dato
letra--> |0X100     | 'a'
nro-->   |0X220     | 5
p -->    |0X300     | 'b'

p 0X300
*p 'b'

int* a = NULL;
int b=3;

1) a = &b;
2) *a = 7;


MEMORIA
dir   var    dato
0X100 b -->  7
0X104 a -->  0X100

NULL  = 0X100



int n1 = 2, n2 = 3;

memoria
0X100 n1 7
0X104 n2 3

n1=n2;

n1=7;


int *a;
int b, c;

b = 15; // Asignamos el valor 15 a lavariable 'b'
a = &b; // Obtenemos la posición de memoria de'b' con el  operador'&'
c = *a; // Copiamos el contenido apuntado por el puntero 'a'

esta    guarda
0x100 a 0x104
0x104 b 15
0x108 c 15

//

int* a;
int* b;
int c;

a = &c; // Obtenemos la posición de memoria de'c' conel  operador'&'
b = a;  // Asignamosel valor del puntero'a' al puntero'b'

variable | esta  | guarda dato
a        | 0x100 | 0x108
b        | 0x104 | 0x108
c        | 0x108 | basura

int vec[5];

variable | esta  | guarda dato
vec[0]   | 0x100 | 1
vec[1]   | 0x104 | 2
vec[2]   | 0x108 | 3
vec[3]   | 0x112 | 4
vec[4]   | 0x116 | 5

sizeof(int)

vec -> 0X100 + sizeof(int) * 0 --> 0x100
vec -> 0X100 + sizeof(int) * 1 --> 0x104
vec -> 0X100 + sizeof(int) * 2 --> 0x108

vec == &vec[0]

*/

/*#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a = 17;
	int *punteroInt;
	int **punteroPuntero;

	punteroInt = &a; // Obtenemos la posición de memoria
	punteroPuntero = &punteroInt; // Obtenemos la posición de memoria

	printf("El valor de a es: %d", a);
	printf("\npunteroInt - valor: %p y valor de lo apuntado: %d", punteroInt, *punteroInt);
	printf("\npunteroPuntero - valor: %p, valor de lo apuntado: %p y valor de lo apuntado apuntado: %d", punteroPuntero, *punteroPuntero, **punteroPuntero);	/*
/*
variable       | esta  | guarda dato
a              | 0x100 | basura
punteroInt     | 0x104 | 0x100
punteroPuntero | 0x108 | 0x104
*/



	/*
	int vec[5];
	int *ptrInt;
	int i;

	ptrInt = vec; //ptrInt = &vec[0];

	for( i=0; i<5; i++){
		*(ptrInt+i) = i+1;
	}

	for( i=0; i<5; i++){
		if(i < 4){
		printf("%p - ", *(ptrInt+i));
		}
		else{
			printf("%p", *(ptrInt+i));
		}
	}
	*/

	/*
	for( i=0; i<5; i++){
		vec[i]=i+1;
	}

	for( i=0; i<5; i++){
		if(i < 4){
		printf("%d - ", vec[i]);
		}
		else{
			printf("%d", vec[i]);
		}
	}
	*/

	//printf("\n\n%d", sizeof(int));

}



