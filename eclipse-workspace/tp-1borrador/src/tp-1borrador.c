/*
 ============================================================================
 Name        : tp-1borrador.c
			SEBASTIAN SERRANO
 DIVISION     : K-1

 ENUNCIADO:
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
6. Salir

DUDAS
Debemos mostrar la lista de precios para los valores acumulados? o mostrar cada vez que ingresa?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float debitar(float a);
float creditos(float a);

int main(void)
{
	setbuf(stdout, NULL);

	char respuestaUsuario;
	float kmIngresados, precioAerolineas, precioLatam;
	float debitoAerolineas, debitoLatam;
	float creditoAerolineas, creditoLatam;
	do
	{
		//Ingreso y valido datos:
		printf("Ingrese la distancia del vuelo en kilometros: \n");
		scanf("%f", &kmIngresados);
		while(kmIngresados < 500 || kmIngresados > 25000 )
		{
			printf("Error, reingrese la distancia del vuelo: > 500km && < 25000km\n");
			scanf("%f", &kmIngresados);
		}
		printf("Ingrese el precio de vuelo para la empresa Aerolineas: \n");
		scanf("%f", &precioAerolineas);
		while(precioAerolineas < 25000 || precioAerolineas > 1000000)
		{
			printf("Error, reingrese el precio de vuelo: > 25000$ && < 1000000$\n");
			scanf("%f", &precioAerolineas);
		}
		printf("Ingrese el precio de vuelo para la empresa Latam: \n");
		scanf("%f", &precioLatam);
		while(precioLatam < 25000 || precioLatam > 1000000)
		{
			printf("Error, reingrese el precio de vuelo: > 25000$ && < 1000000$\n");
			scanf("%f", &precioLatam);
		}

		//llamada a funciones
		debitoAerolineas = debitar(precioAerolineas);
		debitoLatam = debitar(precioLatam);
		creditoAerolineas = creditos(precioAerolineas);
		creditoLatam = creditos(precioLatam);



		//continuo o cierro el do-while
		printf("¿Desea ingresar otro vuelo? S o N\n");
		fflush(stdin);
		scanf("%c", &respuestaUsuario);
	}while(respuestaUsuario == 'S');

	/*3. Calcular todos los costos:
		a) Tarjeta de débito (descuento 10%)
		b) Tarjeta de crédito (interés 25%)
		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
		d) Mostrar precio por km (precio unitario)
		e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

		funcion float calcularCostos(float a, float b, float c); para cada una de etas, 5 o 6 funciones
		*/
	return EXIT_SUCCESS;
}

float debitar(float a)
{
	float descuentoFinal, descuento = 0.9;

	descuentoFinal =  a * descuento;
	return descuentoFinal;
}

float creditos(float a)
{
	float recargoFinal, recargo = 1.25;

	recargoFinal = a * recargo;
	return recargoFinal;
}

/*Valeriy Pavlov16:42
precio unitario es precio por unidad que en este caso es kilometro
Cesar Navas16:42
pero como se hace eso
el kilometros deberia tener un precio
y no aparece el precio por kilometros
Valeriy Pavlov16:43
preciototal/kilometrostotal

la foto del tp estan mal los calculos, eran ilustrativos nomas, los precios los mostramos cada vuelta, no acumulados, documentar todo, 0 warnings 0 errores,
Sullivan Nathan16:45
entonces en el tp no hay que pedir el ingreso de datos por teclado? simplemente se lo asignamos por defecto?
Valeriy Pavlov16:45
en 1 y 2 si Nathan
el 5 son el default hardcodeado
EL 1, 2 3 4 Y 5 SON BOTONES DE UN MENU!!!!!!!!! CON UN SWITCH HAY QUE HACERLO , ES UN MENU NO UNA ORDEN DESCENDE

INT OPCION;
1,2,3,4,5 HASTA 6 QUE ES DONDE QUIEBRA EL DO WHILE
DO WHILE
priintf opciones ( lo podemos hace ren una funcion void mostrarmenu(void)
SWITCH
CASE

int main(void)
int opcion;
do{
printf("opcion1,2,3,4,5,6,); (esto puede ir en una funcion

switch (opcion)
{
	case 1:
	break;
	case 2:
	break;

	default:
	printf("error, no ingreso una opcion valida.");
	break;
	etc
}
}while(opcion != "6");   //la consola siempre va a volver a mostrar el menu hasta que toques el 6, donde va a ser break
pensa como hacer qu eno pueda entrar en opcion 3 o 4 sino ingreso antes en 1 y 2 o 5
despues, puedo anida un if o switch dentro del case 2 , para que eliga cual aerolinea cquiera
*/
// el ingreso de km y las dos aerolineas las podemos hacer con una sola funcion
//fijate porque devuelve el primer dato
// para validar esos tres datos podes hace run int validar(int minimo, int maximo);
//sigo, int numeroValidado;    numeroValidado = validar(100,200);
// hace sun if en la funcion que retorne 1 si esta en el rango y 0 si es falso digamos,
// numero = funcion(100, "messirve papa", "le pifiaste negri");
// int funcion(int a, char * mensaje, char * mensajeError)
//{
//printf(mensaje);}
//queremos reusarlo? cambiamos el mensaje ... messi = funcion(25, "chau chileno","intenta la prox");
/*/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*#include <stdio.h>

int PedirEnteroPositivo(char mensaje[],char error[]);

int main()
{
    int kilometros;
    int precioLatam;
    int precioAerolineas;

    kilometros = PedirEnteroPositivo("Ingrese los kilometros: ","Error ingreso cero o un numero no positivo, reingrese los kilometros: ");
    precioLatam = PedirEnteroPositivo("Ingrese precioLatam: ","Error ingreso cero o un numero no positivo, reingrese los precios de Latam: ");
    precioAerolineas = PedirEnteroPositivo("Ingrese los precioAerolineas: ","Error ingreso cero o un numero no positivo, reingrese los precios de Aerolineas: ");;

    printf("Kilometros %d\n",kilometros);
    printf("Precio Latam %d\n",precioLatam);
    printf("Precio Aerolineas %d\n",precioAerolineas);

    return 0;
}

int PedirEnteroPositivo(char mensaje[],char error[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}

 */
