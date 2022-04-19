#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int menu(int km, float empre1, float empre2){

	int opcion;

	printf("===================================================================\n");
	printf("\tMENU DE OPCIONES.\n");
	printf("===================================================================\n");
	printf("1. Ingresar kilometros (km = %d).\n", km);
	printf("2. Ingresar precio de vuelos.\n");
	printf("   - Precio vuelo Aerolineas: %.2f\n", empre1);
	printf("   - Precio vuelo Latam: %.2f\n", empre2);
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
	if(get_NumEnte(&opcion, "Ingrese opcion (1-6): ", "Error. Ingrese un numero del 1 al 6\n", 1, 6) == 1){
		printf("Opcion ingresada...\n");
	}
	else{
		opcion = 8;
	}
	printf("===================================================================\n");
	return opcion;
}


void informe(char* pMensaje, float empresa, float debito, float credito, float bitCoin, float unitario){

	printf("Precio %s: $%.2f\n", pMensaje, empresa);
	printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
	printf("c) Precio pagando con bitcoin: %.2f BTC\n", bitCoin);
	printf("d) Mostrar precio unitario: $%.2f\n\n", unitario);

}


int cargaForzada(){

	int opcion;

	printf("Ingrese la opcion que desea cambiar:\n");
	printf("1) kilometros.\n");
	printf("2) Precio de vuelos.\n");
	if(get_NumEnte(&opcion, "Ingrese opcion (1 o 2): ", "Error. Ingrese un numero del 1 al 2\n", 1, 2) == 1){
		printf("Opcion ingresada correctamente.\n");
	}
	return opcion;
}













