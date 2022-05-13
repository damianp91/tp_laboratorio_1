#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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



int addPassenger(ePassenger lista[], int tam, int* pId, char name[], char lastName[], float price, char flyCode[], int typePassenger){
	int retorno = 0;
	int indice;
	ePassenger auxLista;

	if(lista != NULL && name != NULL && lastName != NULL && pId != NULL && flyCode != NULL && tam > 0){

		indice = searchEmpty(lista, tam);

		if(indice == -1){

			printf("No hay lugar para guardar esta persona.\n");

		}else{

			auxLista.id = *pId;
			(*pId)++;

			while(!get_String(name, "Ingrese nombre: ", "Error. Nombre demasiado largo.\n", 51)){
				printf("Vuelva a ingresar dato.\n");
			}

			name[0] = toupper(name[0]);

			strcpy(auxLista.name, name);

			while(!get_String(lastName, "Ingrese apellido: ", "Error. Apellido demasiado largo.\n", 51)){
				printf("Vuelva a ingresar dato.\n");
			}

			lastName[0] = toupper(lastName[0]);

			strcpy(auxLista.lastName, lastName);

			while(!get_NumFlota(&price, "Ingrese precio de vuelo: ", "Error. valor fuera de rango (0 a 500.000)", 0, 500000)){
				printf("Vuelva a ingresar dato.\n");
			}

			auxLista.price = price;

			while(!get_String(flyCode, "Ingrese destino: ", "Error. Nombre demasiado largo.\n", 10)){
				printf("Vuelva a ingresar dato.\n");
			}

			flyCode[0] = toupper(flyCode[0]);

			strcpy(auxLista.flyCode, flyCode);

			while(!get_NumEnte(&typePassenger, "\n1) TURISTA.\n2) NEGOCIOS.\n3) PRIMERA CLASE.\nIngrese tipo de vuelo: ", "Error. elija una opcion de 1 a 3\n", 1, 3)){
				printf("Vuelva a ingresar dato.\n");
			}

			auxLista.typePassenger = typePassenger;

			auxLista.isEmpty = 0;

			lista[indice] = auxLista;

			retorno = 1;

		}

	}

	return retorno;
}


int findPassengerById(ePassenger lista[], int tam, int iD){
	int retorno = -1;

	if(lista != NULL && tam > 0 && iD){

		for(int i = 0; i < tam; i ++){

			if(!lista[i].isEmpty && lista[i].id == iD){

				retorno = i;
				break;

			}

		}

	}

	return retorno;
}


int removePassenger(ePassenger lista[], int tam, int iD){
	int retorno = -1;
	int indice;
	char baja;

	if(lista != NULL && tam > 0){

		printf("================================================\n");
		printf("\t      ***BAJA PASAJERO***\n");
		printf("================================================\n");

		if(!get_NumEnte(&iD, "Ingrese id de la persona: ", "Id no esta registrado. ", 1, 2000)){
			printf("Intente de nuevo.\n");
		}

		indice = findPassengerById(lista, tam, iD);

		if(indice < 0){

			printf("El id ingresado no esta registrado en sistema.\n");

		}

		else{

			printf(" ID        NOMBRE        APELLIDO         PRECIO         ESTADO         CLASE\n");
			printf("------------------------------------------------------------------------------\n");

			printPassenger(lista[indice]);

			while(!get_Caracter(&baja, "¿Esta seguro de dar de baja a esta persona? ", "Error. Haga una eleccion entre 's' o 'n'\n", 'n', 's')){
				printf("Vuelva a ingresar dato.\n");
			}

			printf("================================================\n");

			if(baja == 's'){

				lista[indice].isEmpty = 1;
				retorno = 1;

			}

			else{

				printf("Se ha cancelado baja por usuario.\n");

			}

		}


	}

	return retorno;

}


void printPassenger(ePassenger pasajero){

	printf(" %2d    %10s    %10s           %2.f      %10s         %2d\n", pasajero.id,
																	      pasajero.name,
																	      pasajero.lastName,
																	      pasajero.price,
																	      pasajero.flyCode,
																	      pasajero.typePassenger);

}


int printPassengers(ePassenger lista[], int tam){
	int retorno = 0;

	if(lista != NULL && tam > 0){

		printf("==============================================================================\n");
		printf("\t             ***LISTADO DE PASAJEROS***\n");
		printf("==============================================================================\n");
		printf(" ID        NOMBRE        APELLIDO         PRECIO         ESTADO         CLASE\n");
		printf("------------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i ++){

			if(!lista[i].isEmpty){

				printPassenger(lista[i]);

			}

		}

		printf("==============================================================================\n");

		retorno = 1;

	}

	return retorno;
}









