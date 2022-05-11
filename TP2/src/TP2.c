/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define TAM 3

int main(void) {
	setbuf(stdout, NULL);
	ePassenger pasajero[TAM];
	char seguir = 's';

	initPassengers(pasajero, TAM);

	do{

		switch(menuInicial()){

		case 1:

			printf("alta\n");
			break;

		case 2:

			printf("modificar\n");
			break;

		case 3:

			printf("baja\n");
			break;

		case 4:

			printf("informar\n");
			break;

		case 5:

			printf("salir\n");
			seguir = 'n';
			break;

		}

	system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}







