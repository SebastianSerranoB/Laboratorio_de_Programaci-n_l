/*
 ============================================================================
 Name        : notasPARCIAL.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
//2022-04-27 1F
#define LIBRE 0
#define OCUPADO 1
#define EMPLEADOS 100

typedef struct{
	int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
	int id;
	char descripcion[31];
}eSector;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    int cantidadHoras;
    float sueldoBruto;
    float sueldoNeto;

    int idSector;
    eFecha fechaIngreso;
    eFecha fechaNacimiento;

	int estado;
}eEmpleado;

//Empleados: 1, 2, 3, 4, 5, 6, 7, 8
//Sectores: 1, 2, 3

//empelado[indice].legajo = 1;
//empelado[indice].idSector = 1;

//empelado[indice].legajo = 2;
//empelado[indice].idSector = 1;

//empelado[indice].legajo = 3;
//empelado[indice].idSector = 3;

//empelado[indice].legajo = 4;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 5;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 6;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 7;
//empelado[indice].idSector = 1;






//Relaciones entre estructuras o entidades
//1 a 1 - Ok
//1 a muchos / muchos a 1
//muchos a muchos

//50 empleados (estructura eEmpleado)
//50 puestos (estructura ePuesto)
typedef struct{
	int id;
	char descripcion[31];
	...
	//int legajoEmpleado;
}ePuesto;

typedef struct{
    int legajo;
    char nombre[20];
    int idSector;
    eFecha fechaIngreso;
    eFecha fechaNacimiento;
    int idPuesto;
    int estado;
}eEmpleado;






eEmpleado lista[EMPLEADOS];
eSector sectores[3];

void cargarEmpleado(eEmpelado lista[],  int tamanio); //prototipo

cargarEmpleado(lista,  T); // llamada

//Cuerpo, desarrollo, definicion de la funcion
void cargarEmpleado(eEmpelado lista[],  int tamanio){

}



eSector sectores[3] = { {1,"Contabilidad"}, {2,"Sistemas"}, {3, "RRHH"} };
eSector sectores[3] = { 1,"Contabilidad", 2,"Sistemas", 3, "RRHH" };

//

void inicializarEmpleados(eEmpleado lista[], int tam);

inicializarEmpleados(lista, EMPLEADOS); //llamada

void inicializarEmpleados(eEmpleado lista[], int tam){
    int i;

	for(i=0; i<tam; i++){
    		lista[i].estado = LIBRE;
	}
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam);

hardcodearDatosEmpleados(lista, EMPLEADOS); //llamada

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
	int i;
    int legajos[] = {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Marcos","Pedro","Ana","Marcela"};
    char sexo[]= {'M','F','M','M','M','M'};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,3,2};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}


int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

indice = buscarLibre(lista, EMPLEADOS);

if( indice != -1 ){
	//alta
}
else{
	//No hay espacio
}

#define SECTORES 3
#define EMPLEADOS 6

eSectores listaSectores[SECTORES];

//listar sectores - Ok
//ingresar el sector determinado a listar los empleados - Ok
//Recorrer los empleados
//encontrar y mostrar los del sector correspondiente

listarSectores(listaSectores, SECTORES);

printf("Codigo de sector");
scanf("%d", &sectorAux);

for(i=0; i<SECTORES; i++){
	if( sectorAux == listaSectores[i].id ){
		printf("%s", listaSectores[i].descripcion);
		break;
	}
}

for(i=0; i<EMPLEADOS; i++){
	if( sectorAux == empleados[i].idSector ){
		printf("\n%s", empleado[i].nombre);
	}
}

//
int i, j;

listarSectores(listaSectores, SECTORES);

printf("Codigo de sector");
scanf("%d", &sectorAux);

for(i=0; i<SECTORES; i++){
	if( sectorAux == listaSectores[i].id ){
		for(j=0; j<EMPLEADOS; j++){
			if( sectorAux == empleados[j].idSector ){
				printf("\n%s\t%s", empleado[j].nombre, sector[i].descripcion);
			}
		}
		break;
	}
}


//2022-04-27 1F
#define LIBRE 0
#define OCUPADO 1
#define EMPLEADOS 100

typedef struct{
	int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
	int id;
	char descripcion[31];
}eSector;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    int cantidadHoras;
    float sueldoBruto;
    float sueldoNeto;

    int idSector;
    eFecha fechaIngreso;
    eFecha fechaNacimiento;

	int estado;
}eEmpleado;

//Empleados: 1, 2, 3, 4, 5, 6, 7, 8
//Sectores: 1, 2, 3

//empelado[indice].legajo = 1;
//empelado[indice].idSector = 1;

//empelado[indice].legajo = 2;
//empelado[indice].idSector = 1;

//empelado[indice].legajo = 3;
//empelado[indice].idSector = 3;

//empelado[indice].legajo = 4;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 5;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 6;
//empelado[indice].idSector = 2;

//empelado[indice].legajo = 7;
//empelado[indice].idSector = 1;






//Relaciones entre estructuras o entidades
//1 a 1 - Ok
//1 a muchos / muchos a 1
//muchos a muchos

//50 empleados (estructura eEmpleado)
//50 puestos (estructura ePuesto)
typedef struct{
	int id;
	char descripcion[31];
	...
	//int legajoEmpleado;
}ePuesto;

typedef struct{
    int legajo;
    char nombre[20];
    int idSector;
    eFecha fechaIngreso;
    eFecha fechaNacimiento;
    int idPuesto;
    int estado;
}eEmpleado;






eEmpleado lista[EMPLEADOS];
eSector sectores[3];

void cargarEmpleado(eEmpelado lista[],  int tamanio); //prototipo

cargarEmpleado(lista,  T); // llamada

//Cuerpo, desarrollo, definicion de la funcion
void cargarEmpleado(eEmpelado lista[],  int tamanio){

}



eSector sectores[3] = { {1,"Contabilidad"}, {2,"Sistemas"}, {3, "RRHH"} };
eSector sectores[3] = { 1,"Contabilidad", 2,"Sistemas", 3, "RRHH" };

//

void inicializarEmpleados(eEmpleado lista[], int tam);

inicializarEmpleados(lista, EMPLEADOS); //llamada

void inicializarEmpleados(eEmpleado lista[], int tam){
    int i;

	for(i=0; i<tam; i++){
    		lista[i].estado = LIBRE;
	}
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam);

hardcodearDatosEmpleados(lista, EMPLEADOS); //llamada

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
	int i;
    int legajos[] = {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Marcos","Pedro","Ana","Marcela"};
    char sexo[]= {'M','F','M','M','M','M'};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,3,2};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}


int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

indice = buscarLibre(lista, EMPLEADOS);

if( indice != -1 ){
	//alta
}
else{
	//No hay espacio
}

#define SECTORES 3
#define EMPLEADOS 6

eSectores listaSectores[SECTORES];

//listar sectores - Ok
//ingresar el sector determinado a listar los empleados - Ok
//Recorrer los empleados
//encontrar y mostrar los del sector correspondiente

listarSectores(listaSectores, SECTORES);

printf("Codigo de sector");
scanf("%d", &sectorAux);

for(i=0; i<SECTORES; i++){
	if( sectorAux == listaSectores[i].id ){
		printf("%s", listaSectores[i].descripcion);
		break;
	}
}

for(i=0; i<EMPLEADOS; i++){
	if( sectorAux == empleados[i].idSector ){
		printf("\n%s", empleado[i].nombre);
	}
}

//
int i, j;

listarSectores(listaSectores, SECTORES);

printf("Codigo de sector");
scanf("%d", &sectorAux);

for(i=0; i<SECTORES; i++){
	if( sectorAux == listaSectores[i].id ){
		for(j=0; j<EMPLEADOS; j++){
			if( sectorAux == empleados[j].idSector ){
				printf("\n%s\t%s", empleado[j].nombre, sector[i].descripcion);
			}
		}
		break;
	}
}


//Relacion entre estructuras o entidades
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
	int idAutor;
	char nombre[31];
	int nacionalidad;
	eFecha fechaNac;
	int estado;
}eAutor;

typedef struct{
	int idLibro
	char titulo[31];
	char isbn[31];
	int estado;
}eLibro;

typedef struct{
	int idLibro;
	int idAutor;
}eLibroAutor;

libro 1 a autores muchos
libros muchos autor 1
muchos a muchos

1 - Lenguaje de Programacion C
2 - Como programar en C, C++ y Java
3 - Martin Fierro
4 - De la Tierra a la Luna
5 - Viaje al centro de la Tierra
6 - Como programar en C++

1 - Ritchie
2 - Deitel H.
3 - Deitel P.
4 - Kernighan
5 - Jose Hernandez
6 - Julio Verne

eLibroAutor libroAutor[] = { {1, 1}, {2, 2}, {2, 3}, {3, 5 }, {4, 6}, {5, 6}, {6, 2}, {6, 3}, {1, 4} };

//listar autores
//ingreso busqueda de autor
//recorro autores
//recorro eLibroAutor
//recorrer Libros


//listar libros
//ingreso busqueda de libro
//recorro libros
//recorro eLibroAutor
//recorrer autores

//1 autor escribio 1 o mas libros
//1 libro es escrito por uno o mas de un autor

//Deitel & Deitel

//Listar autores listado - Ok
//ingreso dato a buscar - Ok
//Mostrar el autor seleccionado:
//Recorrer Autores
//muestro de acuerdo a lo buscado
//Recorrer Libros for - Ok
//Buscar con el idAutor if - Ok
//muestro - Ok

#define AUTORES 5
#define LIBROS 10


void listarAutores( eAutor, int );

int main(){
	eLibro libros[LIBROS];
	eAutor autores[AUTORES];
	int i, idAutorAux;

	listarAutores(autores, AUTORES);

	printf("Codigo de autor a buscar: ");
	scanf("%d", &idAutorAux);

	for( i=0; i< AUTORES; i++ ){
		if( idAutorAux == autores[i].idAutor ){
			printf( "%s", autores[i].nombre );
			break;
		}
	}

	for( i=0; i< LIBROS; i++ ){
		if( idAutorAux == libros[i].idAutor ){
			printf("%s", libros[i].titulo);
		}
	}
}











void listarAutores( eAutor autores[], int tamanio ){
	int i;

	printf( "Id\tAutor" );
	for( i=0; i< tamanio; i++ ){
		if( autores[i].estado == 1 ){
			printf( "%d\t%s", autores[i].idAutor, autores[i].nombre );
		}

	}
}





//Cardionalidad
// 1 a 1
// 1 a muchos
//muchos a muchos





#define AUTORES 5
#define LIBROS 10


void listarAutores( eAutor, int );

int main(){
	eLibro libros[LIBROS];
	eAutor autores[AUTORES];
	eLibroAutor librosAutores[LIBROS * AUTORES];
	int i, j, k, idAutorAux;

	listarAutores(autores, AUTORES);

	printf("Codigo de autor a buscar: ");
	scanf("%d", &idAutorAux);

	for( i=0; i< AUTORES; i++ ){
		if( idAutorAux == autores[i].idAutor ){
			for(j=0; j< LIBROS * AUTORES; j++){
				if( librosAutores[j].idAutor == autores[i].idAutor ){
					for( k=0; k<LIBROS; k++ ){
						if( libros[k].idLibro == librosAutores[j].idLibro ){
							printf("%s\t%s", autores[i].nombre, libros[k].titulo);
						}
					}
				}
			}
			break;
		}
	}



	for( i=0; i< LIBROS; i++ ){
		if( idAutorAux == libros[i].idAutor ){
			printf("%s", libros[i].titulo);
		}
	}
}

RELACIONES ENTRE ESTRUCTURAS O ENTIDADES

-1 A 1
-1 A MUCHOS / MUCHOS A 1     //el 1 tiene que estar dentro del muchos y viceversa
-MUCHOS A MUCHOS

50 EMPLEADOS(estructura eEmpleado)
cada uno con su escritorio, pc, puesto.
un solo turno laboral
entonces
//50 puestos(estructura ePuesto) {escritorio,silla,pc,etc}
 1 empleado para un puesto RELACION 1 a -1

EVITAR REDUNDANCIA






