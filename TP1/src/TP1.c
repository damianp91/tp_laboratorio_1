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


int main(void) {
	setbuf(stdout, NULL);
	char seguir = 'n';
	float km;
	float vAero;
	float laTam;

	do{
		switch(menu()){
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

			printf("Calculo costos\n");
			break;

		case 4:

			printf("Informe\n");
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








