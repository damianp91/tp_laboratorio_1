/*
 ============================================================================
 Name        : TP2.c
 Author      : Cristian Damian Posada Vargas
 Version     : 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "menuListas.h"

#define TAM 2000
#define TAM_PASS 3
#define TAM_STATUS 6
#define ASC 1
#define DESC 0

int main(void) {
	setbuf(stdout, NULL);
	char seguir = 's';
	int idPass = 1;
	int idBaja = 0;
	char nombre[51];
	char apellido[51];
	float precio = 0;
	int tipoPasajero = 0;
	char destino[10];
	int contAlt = 0;
	ePassenger pasajeros[TAM];

	eTypePass tipoPasajeros[TAM_PASS] = {

			{1, "TURISTA"},
			{2, "NEGOCIOS"},
			{3, "EXCLUSIVO"}

	};
	eStatus estados[TAM_STATUS] = {

			{1, "EN ESPERA"},
			{2, "RETRASADO"},
			{3, "A TIEMPO"},
			{4, "DESPEGANDO"},
			{5, "ATERRIZANDO"},
			{6, "EN VUELO"}

	};

	initPassengers(pasajeros, TAM);

	do{

		switch(menuInicial()){

		case 1:

			if(addPassenger(pasajeros, TAM, &idPass, nombre, apellido, precio, tipoPasajero, destino, tipoPasajeros, TAM_PASS, estados, TAM_STATUS)){
				printf("Datos de pasagero agregados con exito.\n");
				contAlt ++;

			}

			break;

		case 2:

			if(contAlt){
				replaceFieldPassenger(pasajeros, TAM, tipoPasajeros, TAM_PASS, estados, TAM_PASS);

			}

			else{

				printf("Primero debe ingresar por lo menos un pasajero para hacer esta accion\n");

			}

			break;

		case 3:

			if(contAlt){
				removePassenger(pasajeros, TAM, idBaja, tipoPasajeros, TAM_PASS, estados, TAM_STATUS);
				contAlt --;
			}

			else{

				printf("Primero debe ingresar por lo menos un pasajero para hacer esta accion\n");

			}

			break;

		case 4:

			if(contAlt){
				sortPassengers(pasajeros, TAM, ASC);
				printPassengers(pasajeros, TAM, tipoPasajeros, TAM_PASS, estados, TAM_STATUS);
				printf("Listado final por apellido y tipo de pasajero\n");

				sortPassengersByCode(pasajeros, TAM, ASC);
				printPassengers(pasajeros, TAM, tipoPasajeros, TAM_PASS, estados, TAM_STATUS);
				printf("Listado final por destino y estado de vuelo\n");
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


