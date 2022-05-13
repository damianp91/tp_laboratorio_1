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
	int iD = 1, auxId, typePassenger, flagCarga = 0;
	char seguir = 's', name[51], lastName[51], flyCode[10];
	float price;

	initPassengers(pasajero, TAM);

	do{

		switch(menuInicial()){

		case 1:

			if(addPassenger(pasajero, TAM, &iD, name, lastName, price, flyCode, typePassenger)){
				printf("Datos de pasagero agregados con exito.\n");
				flagCarga = 1;
			}

			break;

		case 2:

			printf("modificar\n");
			break;

		case 3:

			if(removePassenger(pasajero, TAM, auxId) && flagCarga){
				printf("Pasajero dado de baja.\n");
			}

			else{

				printf("Primero debe ingresar por lo menos un pasajero para hacer esta accion\n");

			}

			break;

		case 4:

			if(printPassengers(pasajero, TAM) && flagCarga){
				printf("Listado final\n");
			}

			else{
				printf("Primero debe ingresar por lo menos un pasajero para hacer esta accion\n");
			}

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






