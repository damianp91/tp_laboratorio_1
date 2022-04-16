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


int menu();




int main(void) {
	setbuf(stdout, NULL);
	char seguir = 'n';
	float km;
	float vAero;
	float laTam;

	do{
		switch(menu()){
		case 1:


			printf("Ingreso de km.\n");
			break;

		case 2:


			printf("Ingreso de precios\n");
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

			printf("¿Esta seguro que desea salir? (s/n)\n");
			fflush(stdin);
			scanf("%c", &seguir);
			if(seguir == 'n'){
				printf("Salida cancelada.\n");
			}else{
				printf("Saliendo...\n");
				seguir = 's';
			}
			break;

		default:

			printf("¡Opcion incorrecta!\n");
			break;
		}

		system("pause");
		printf("\n\n");

	}while(seguir == 'n');

	return EXIT_SUCCESS;
}



int menu(){

	int opcion;

	printf("===================================================================\n");
	printf("\tMENU DE OPCIONES.\n");
	printf("===================================================================\n");
	printf("1. Ingresar kilometros (km).\n");
	printf("2. Ingresar precio de vuelos:\n");
	printf("   - Precio vuelo Aerolineas.\n");
	printf("   - Precio vuelo Latam.\n");
	printf("3. Calcular los costos:\n");
	printf("   a)Tarjeta de debito (descuento 10 porciento).\n");
	printf("   b)Tarjeta de credito (interes 25 porciento).\n");
	printf("   c)Bitcoin (1 BTC -> 4,609,731.71 ARS).\n");
	printf("   d)Mostrar precio por km (precio unitario).\n");
	printf("   e)Mostrar diferencia de precio ingresada (Latam - Aerolineas).\n");
	printf("4. Informar resultados.\n");
	printf("5. Carga forzada de datos.\n");
	printf("6. Salir.\n");
	printf("-------------------------------------------------------------------\n");
	printf("Ingrese opcion (1 a 6): ");
	scanf("%d", &opcion);
	printf("===================================================================\n");

	return opcion;
}










