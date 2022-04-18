/*
 *
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menuAgencia.h"
#include "operaciones.h"


int main(void) {
	setbuf(stdout, NULL);
	char seguir = 'n';
	float km = 0;
	float vAero = 0; float dAero; float cAero; float bAero; float uAero;
	float laTam = 0; float dLatam; float cLatam; float bLatam; float uLatam;

	do{
		switch(menu(km, vAero, laTam)){
		case 1:


			if(get_NumFlota(&km, "Ingrese total de kilometros(km) de vuelo: ", "¡Datos incorrectos!\n", 8.0, 22000.0) == 1){
				printf("Kilometros ingresados correctamente.\n");
			}
			break;

		case 2:

			if(get_NumFlota(&vAero, "Ingrese precio total de vuelo Aerolineas: ", "¡Datos incorrectos!\n", 0.0, 900000.0) == 1){
				printf("Precio Aerolineas ingresado correctamente.\n\n");
			}

			if(get_NumFlota(&laTam, "Ingrese precio total de vuelo Latam: ", "¡Datos incorrectos!\n", 8.0, 900000.0) == 1){
				printf("Precio Latam ingresado correctamente.\n\n");
			}
			break;

		case 3:

			debitoDes10(vAero, &dAero);
			creditoInte25(vAero, &cAero);
			bitCoin(vAero, &bAero);
			preUnitario(vAero, km, &uAero);

			debitoDes10(laTam, &dLatam);
			creditoInte25(laTam, &cLatam);
			bitCoin(laTam, &bLatam);
			preUnitario(laTam, km, &uLatam);
			break;

		case 4:

			informe("Aerolineas", vAero, dAero, cAero, bAero, uAero);
			informe("Latam", laTam, dLatam, cLatam, bLatam, uLatam);
			break;

		case 5:

			printf("Carga forzada\n");
			break;

		case 6:

			get_Caracter(&seguir, "¿Esta seguro que desea salir? (s/n): ", "Error. Elija una opcion entre s o n: \n", 'n', 's');
			if(seguir == 's'){
				printf("Saliendo...\n");
				seguir = 's';
			}
			else{
				printf("Salida cancelada.\n");
			}
			break;

		}

		system("pause");
		printf("\n\n");

	}while(seguir == 'n');

	return EXIT_SUCCESS;
}

