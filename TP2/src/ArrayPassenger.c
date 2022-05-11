#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"



int menuInicial(){
	int opcion;

	printf("===================================\n");
	printf("\t   ***MENU***\n");
	printf("-----------------------------------\n");
	printf("\t1) ALTAS.\n");
	printf("\t2) MODIFICAR.\n");
	printf("\t3) BAJA.\n");
	printf("\t4) INFORMAR.\n");
	printf("\t5) SALIR.\n");
	printf("===================================\n");

	while(!get_NumEnte(&opcion, "Ingrese opcion: ", "Error. opcion fuerla del limite 1 a 5\n", 1, 5)){
		printf("Intente de nuevo.\n");

	}

	return opcion;
}



int initPassengers(ePassenger lista[], int tam){
	int retorno = 0;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			lista[i].isEmpty = 1;

		}

		retorno = -1;

	}

	return retorno;
}



int searchEmpty(ePassenger lista[], int tam){
	int retorno = -1;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			if(lista[i].isEmpty){

				retorno = i;
				break;

			}

		}

	}

	return retorno;

}






















