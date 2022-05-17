#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "menuListas.h"



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



int addPassenger(ePassenger lista[], int tam, int* pId, char name[], char lastName[], float price, int typePassenger, char flyCode[], eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta){
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


			listaTypePass(tipos, tamTip);

			while(!get_NumEnte(&typePassenger, "Ingrese tipo de pasajero: ", "Error. Debe elejir entre 1 a 3.\n", 1, 3)){
				printf("Vuelva a ingresar dato.\n");
			}

			auxLista.idPass.iD = typePassenger;

			while(!get_String(flyCode, "Ingrese destino: ", "Error. destino demasiado largo.\n", 10)){
				printf("Vuelva a ingresar dato.\n");
			}

			strcpy(auxLista.flyCode, flyCode);

			listaStatusPass(estados, tamEsta);

			while(!get_NumEnte(&auxLista.idFly.iD, "Ingrese estado de vuelo: ", "Error. Debe elejir entre 1 a 6.\n", 1, 6)){
				printf("Vuelva a ingresar dato.\n");
			}

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



int removePassenger(ePassenger lista[], int tam, int iD, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta){
	int retorno = -1;
	int indice;
	char baja;

	if(lista != NULL && tipos != NULL && tamTip > 0 && tam > 0){

		printf("======================================================================================================\n");
		printf("\t      ***BAJA PASAJERO***\n");
		printf("======================================================================================================\n");

		if(!get_NumEnte(&iD, "Ingrese id de la persona: ", "Id no esta registrado. ", 1, 2000)){
			printf("Intente de nuevo.\n");
		}

		indice = findPassengerById(lista, tam, iD);

		if(indice < 0){

			printf("El id ingresado no esta registrado en sistema.\n");

		}

		else{

			printf(" ID        NOMBRE        APELLIDO         PRECIO             DESTINO         TIPO            STATUS\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			printPassenger(lista[indice], tipos, tamTip, estados, tamEsta);

			while(!get_Caracter(&baja, "¿Esta seguro de dar de baja a esta persona? ", "Error. Haga una eleccion entre 's' o 'n'\n", 'n', 's')){
				printf("Vuelva a ingresar dato.\n");
			}

			printf("======================================================================================================\n");

			if(baja == 's'){

				printf("Pasajero dado de baja.\n");
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



int pasajeIdTipo(eTypePass tipos[], int tam, int iD, char descripcion[]){
	int retorno = 0;

	if(tipos != NULL && descripcion != NULL && tam > 0){

		for(int i = 0; i < tam; i ++){

			if(tipos[i].iD == iD){

				strcpy(descripcion, tipos[i].description);
				break;

			}

		}

		retorno = 1;

	}

	return retorno;
}



int pasajeIdStatus(eStatus estados[], int tamEsta, int iD, char descripcion[]){
	int retorno = 0;

	if(estados != NULL && descripcion != NULL && tamEsta > 0){

		for(int i = 0; i < tamEsta; i ++){

			if(estados[i].iD == iD){

				strcpy(descripcion, estados[i].descripcion);
				break;

			}

		}

		retorno = 1;

	}

	return retorno;
}



void printPassenger(ePassenger pasajero, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta){
	char descripTipo[20];
	char descripStatus[20];

	pasajeIdTipo(tipos, tamTip, pasajero.idPass.iD, descripTipo);

	pasajeIdStatus(estados, tamEsta, pasajero.idFly.iD, descripStatus);

	printf(" %2d    %10s    %10s           %2.f ARS      %10s         %-10s      %-10s\n", pasajero.id,
																	                       pasajero.name,
																	                       pasajero.lastName,
																	                       pasajero.price,
																	                       pasajero.flyCode,
																				           descripTipo,
																				           descripStatus);

}



int printPassengers(ePassenger lista[], int tam, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta){
	int retorno = 0;
	int flag = 1;

	if(lista != NULL && tipos != NULL && tamTip > 0 && tam > 0){

		printf("======================================================================================================\n");
		printf("\t             ***LISTADO DE PASAJEROS***\n");
		printf("======================================================================================================\n");
		printf(" ID        NOMBRE        APELLIDO         PRECIO             DESTINO         TIPO            STATUS\n");
		printf("------------------------------------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i ++){

			if(!lista[i].isEmpty){

				printPassenger(lista[i], tipos, tamTip, estados, tamEsta);
				flag = 0;

			}

		}

		printf("======================================================================================================\n");

		if(flag){
			printf("No hay pasajeros para mostrar.\n");
		}

		retorno = 1;

	}

	return retorno;
}



int replaceFieldPassenger(ePassenger lista[], int tam, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta){
	int retorno = -1;
	int indice;
	int iD;
	char modificar;
	ePassenger auxPasajero;

	if(lista != NULL && tipos != NULL && tamTip > 0 && tam > 0){

		printf("======================================================================================================\n");
		printf("\t      ***MODIFICAR PASAJERO***\n");
		printf("======================================================================================================\n");

		if(!get_NumEnte(&iD, "Ingrese id de pasajero: ", "Id no esta registrado. ", 1, 2000)){
			printf("Intente de nuevo.\n");
		}

		indice = findPassengerById(lista, tam, iD);

		if(indice < 0){

			printf("El id ingresado no esta registrado en sistema.\n");

		}

		else{

			printf(" ID        NOMBRE        APELLIDO         PRECIO             DESTINO         TIPO            STATUS\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			printPassenger(lista[indice], tipos, tamTip, estados, tamEsta);

			while(!get_Caracter(&modificar, "¿Esta seguro de modificar datos de este pasajero? ", "Error. Haga una eleccion entre 's' o 'n'\n", 'n', 's')){
				printf("Vuelva a ingresar dato.\n");
			}

			printf("======================================================================================================\n");

			if(modificar == 's'){

				switch(subMenuPass()){

				case 1:

					while(!get_String(auxPasajero.name, "Ingrese nombre: ", "Error. Nombre demasiado largo.\n", 51)){
						printf("Vuelva a ingresar dato.\n");
					}

					auxPasajero.name[0] = toupper(auxPasajero.name[0]);

					strcpy(lista[indice].name, auxPasajero.name);

					break;

				case 2:

					while(!get_String(auxPasajero.name, "Ingrese apellido: ", "Error. Apellido demasiado largo.\n", 51)){
						printf("Vuelva a ingresar dato.\n");
					}

					auxPasajero.lastName[0] = toupper(auxPasajero.lastName[0]);

					strcpy(lista[indice].lastName, auxPasajero.lastName);

					break;

				case 3:

					while(!get_NumFlota(&auxPasajero.price, "Ingrese precio de vuelo: ", "Error. valor fuera de rango (0 a 500.000)", 0, 500000)){
						printf("Vuelva a ingresar dato.\n");
					}

					lista[indice].price = auxPasajero.price;

					break;

				case 4:

					while(!get_String(auxPasajero.flyCode, "Ingrese destino de pasajero: ", "Error. Nombre de destino demasiado largo.\n", 10)){
						printf("Vuelva a ingresar dato.\n");
					}

					strcpy(lista[indice].flyCode, auxPasajero.flyCode);

					break;

				case 5:

					listaTypePass(tipos, tamTip);

					while(!get_NumEnte(&auxPasajero.idPass.iD, "Ingrese tipo de pasajero: ", "Error. Debe elejir entre 1 a 3.\n", 1, 3)){
						printf("Vuelva a ingresar dato.\n");
					}

					lista[indice].idPass = auxPasajero.idPass;

					break;

				case 6:

					listaStatusPass(estados, tamEsta);

					while(!get_NumEnte(&auxPasajero.idFly.iD, "Ingrese estado de vuelo: ", "Error. Debe elejir entre 1 a 6.\n", 1, 6)){
						printf("Vuelva a ingresar dato.\n");
					}

					lista[indice].idFly = auxPasajero.idFly;

					break;

				}

				printf("Datos de pasajero modificados con exito.\n");

			}

			else{

				printf("Se ha cancelado baja por usuario.\n");

			}

		}


	}

	return retorno;

}



int sortPassengers(ePassenger lista[], int tam, int criterio){
	int retorno = 0;
	ePassenger auxLista;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i ++){
			for(int j = i + 1; j < tam; j ++){

				if((strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].idPass.iD > lista[j].idPass.iD && criterio) || (strcmp(lista[i].lastName, lista[j].lastName) < 0 && criterio) ||
				   (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].idPass.iD < lista[j].idPass.iD && !criterio) || (strcmp(lista[i].lastName, lista[j].lastName) > 0 && !criterio)){

					auxLista = lista[i];
					lista[i] = lista[j];
					lista[j] = auxLista;

				}

			}
		}

		retorno = 1;

	}

	return retorno;
}



int sortPassengersByCode(ePassenger lista[], int tam, int criterio){
	int retorno = 0;
	ePassenger auxLista;

	if(lista != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i ++){
			for(int j = i + 1; j < tam; j ++){

				if((strcmp(lista[i].flyCode, lista[j].flyCode) == 0 && lista[i].idFly.iD > lista[j].idFly.iD && criterio) || (strcmp(lista[i].flyCode, lista[j].flyCode) < 0 && criterio) ||
				   (strcmp(lista[i].flyCode, lista[j].flyCode) == 0 && lista[i].idFly.iD < lista[j].idFly.iD && !criterio) || (strcmp(lista[i].flyCode, lista[j].flyCode) > 0 && !criterio)	){

					auxLista = lista[i];
					lista[i] = lista[j];
					lista[j] = auxLista;

				}

			}
		}

		retorno = 1;

	}

	return retorno;
}
































