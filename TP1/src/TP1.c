/*
 *
 ============================================================================
 Name        : TP1.c
 Author      : Cristian Damian Posada Vargas
 Version     : 1G
 Copyright   : Your copyright notice
 Description : Muesta de precios de vuelos
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menuAgencia.h"
#include "operaciones.h"


int main(void) {
	setbuf(stdout, NULL);
	char seguir = 'n'; char forzar = 'n';
	int contFlag = 0;
	int km = 0;
	float auxDif;
	float vAero = 0.00; float dAero; float cAero; float bAero; float uAero;
	float laTam = 0.00; float dLatam; float cLatam; float bLatam; float uLatam;

	do{

		switch(menu(km, vAero, laTam)){

		case 1:

			if(get_NumEnte(&km, "Ingrese total de kilometros(km) de vuelo: ", "¡Datos incorrectos!\n", 8.0, 22000.0)){

				printf("Kilometros ingresados correctamente.\n");

				contFlag ++;

			}

			break;

		case 2:

			if(contFlag < 1){

				printf("Primero debe ingresar kilometros para ingresar precios de vuelos.\n");

			}

			else{

				if(get_NumFlota(&vAero, "Ingrese precio total de vuelo Aerolineas: ", "¡Datos incorrectos!\n", 0.0, 900000.0)){

					printf("Precio Aerolineas ingresado correctamente.\n\n");

					contFlag ++;

				}

				if(get_NumFlota(&laTam, "Ingrese precio total de vuelo Latam: ", "¡Datos incorrectos!\n", 8.0, 900000.0)){

					printf("Precio Latam ingresado correctamente.\n\n");

					contFlag ++;

				}

			}

			break;

		case 3:

			if(contFlag < 3){

				printf("Primero debe ingresar kilometros y precios de vuelos para hacer los calculos.\n");

			}

			else{

				debitoDes10(vAero, &dAero);
				creditoInte25(vAero, &cAero);
				bitCoin(vAero, &bAero);
				preUnitario(vAero, km, &uAero);

				debitoDes10(laTam, &dLatam);
				creditoInte25(laTam, &cLatam);
				bitCoin(laTam, &bLatam);
				preUnitario(laTam, km, &uLatam);
				printf("Calculos realizandose...\n");

				contFlag ++;

			}

			break;

		case 4:

			if(contFlag < 4){

				printf("Primero debe ingresar datos de vuelos, kilometros y hacer calculos para hacer el informe.\n");
			}

			else{

				printf("KMs Ingresados: %d\n\n", km);
				informe("Aerolineas", vAero, dAero, cAero, bAero, uAero);
				informe("Latam", laTam, dLatam, cLatam, bLatam, uLatam);

				auxDif = laTam - vAero;

				if(auxDif < 0){

					auxDif *= (-1);

				}

				printf("La diferencia de precio es: $%.2f\n", auxDif);
			}

			break;

		case 5:

			get_Caracter(&forzar, "¿Esta seguro que desea forzar  una carga de datos nueva? (s/n): ", "Error. Elija una opcion entre s o n: \n", 'n', 's');

			if(forzar == 's'){

				if(cargaForzada() == 1){

					if(get_NumEnte(&km, "Ingrese total de kilometros(km) de vuelo: ", "¡Datos incorrectos!\n", 8.0, 22000.0)){

						printf("Kilometros ingresados correctamente.\n");

					}

				}

				else{

					if(get_NumFlota(&vAero, "Ingrese precio total de vuelo Aerolineas: ", "¡Datos incorrectos!\n", 0.0, 900000.0)){

						printf("Precio Aerolineas ingresado correctamente.\n\n");

					}

					if(get_NumFlota(&laTam, "Ingrese precio total de vuelo Latam: ", "¡Datos incorrectos!\n", 8.0, 900000.0)){

						printf("Precio Latam ingresado correctamente.\n\n");

					}

				}

			}

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

		printf("\n");
		system("pause");
		printf("\n\n");

	}while(seguir == 'n');

	return EXIT_SUCCESS;

}

