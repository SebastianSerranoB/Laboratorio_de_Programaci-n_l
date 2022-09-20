/*
 * functions8.h
 *
 *  Created on: 20 abr 2022
 *      Author: admin
 */

#ifndef FUNCTIONS8_H_
#define FUNCTIONS8_H_

#define CANT 5
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 4
#define MAC 5
#define IPAD 6
#define ACCESORIOS 7

int mainMenu(char text[]);


typedef struct{
	int estado;
	int idProducto;
	int nacionalidad;
	int tipo;
	char descripcion[101];
	float precio;

}sProducto;

sProducto alta(void);






void showProduct(sProducto producto);


#endif /* FUNCTIONS8_H_ */
