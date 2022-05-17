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



int subMenuPass(){
	int opcion;

	printf("===================================\n");
	printf("\t   ***MENU***\n");
	printf("-----------------------------------\n");
	printf("\t1) NONBRE.\n");
	printf("\t2) APELLIDO.\n");
	printf("\t3) PRECIO VUELO.\n");
	printf("\t4) DESTINO.\n");
	printf("\t5) SECCION PASAJERO.\n");
	printf("\t6) ESTADO DE VUELO.\n");
	printf("\t7) VOLVER A MENU PRONCIPAL.\n");
	printf("===================================\n");

	while(!get_NumEnte(&opcion, "Ingrese opcion: ", "Error. opcion fuerla del limite 1 a 7\n", 1, 7)){
		printf("Intente de nuevo.\n");

	}

	return opcion;

}



void typePass(eTypePass tipos, int tam){

	printf(" %2d                  %-10s\n", tipos.iD,
			                                tipos.description);

}



int listaTypePass(eTypePass tipos[], int tam){
	int retorno = 0;

	if(tipos != NULL && tam > 0){

		printf("===================================\n");
		printf("     ***TIPO DE PASAJERO***\n");
		printf("-----------------------------------\n");
		printf("   ID                TIPO PASAJERO\n");
		printf("-----------------------------------\n");

		for(int i = 0; i < tam; i ++){

			typePass(tipos[i], tam);

		}

		printf("===================================\n");

		retorno = 1;

	}

	return retorno;

}



void statusPass(eStatus estados, int tam){

	printf(" %2d                %-10s\n", estados.iD,
				                          estados.descripcion);

}



int listaStatusPass(eStatus estados[], int tam){
	int retorno = 0;

	if(estados != NULL && tam > 0){

		printf("===================================\n");
		printf("     ***ESTADO DE VUELO***\n");
		printf("-----------------------------------\n");
		printf("   ID            ESTADO DE VUELO\n");
		printf("-----------------------------------\n");

		for(int i = 0; i < tam; i ++){

			statusPass(estados[i], tam);

		}

		printf("===================================\n");

		retorno = 1;

	}

	return retorno;

}


