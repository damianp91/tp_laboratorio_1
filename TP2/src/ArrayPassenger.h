#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int isEmpty;

}ePassenger;

#endif /* ARRAYPASSENGER_H_ */


/**
 * \Brief funcion no recibe ningun parametro, pero devuelve un numero de tipo int de 1 a 6.
 * \param vacio.
 *
 */
int menuInicial();


/**
 * \Brief indica en todas las posiciones del array en campo isEmpty estan vacias.
 *        esta funcion indica con un TRUE o FALSE segun c++ (0 o int != 0) en todas
 *        las possiciones que existan en el array.
 * \param lista parametro de tipo ePassenger(estructura)
 * \param tam de tipo int indica el tammaño del array
 *
 * \return retorno devuelve un 0 para FALSE o un -1 para un TRUE
 *
 */
int initPassengers(ePassenger lista[], int tam);


/**
 * \Brief Busca en la estructura lista en el campo isEmpty si esta vacio para ser utilizado.
 * \param lista parametro de tipo ePassenger(estructura)
 * \param tam de tipo int indica el tammaño del array
 *
 * \return retorno devuelve un -1 para FALSE o el infice del array para un TRUE
 *
 */
int searchEmpty(ePassenger lista[], int tam);


/**
 * \Brief agrega en una lista existente de tipo struct los valores como parametros in la primers posicion vacia.
 * \param lista de tipo struct
 * \param tam de tipo int tamaño de la lista
 * \param pId puntero a int conteo de pasagers
 * \param name de tipo cadena de caracteres
 * \param lastName de tipo char de caracteres
 * \param price de tipo float precio de vuelo
 * \param flyCode de tipo char de caracteres
 * \param typePassenger de tipo int
 *
 * \return 0 en caso de no poder terminar con exito y 1 si se termina con exito la funcion
 *
 */
int addPassenger(ePassenger lista[], int tam, int* pId, char name[], char lastName[], float price, char flyCode[], int typePassenger);


/**
 * \Brief busca un pasajero por id y retorna el indice en donde se encuentra el mismo
 * \param lista de tipo struct
 * \param tam de tipo int tamaño de la lista
 * \param iD de tipo int
 *
 * \return retorna un -1 si no se pudo hacer nada en la funcion o el indice del lugar en donde esta el pasajero
 *
 */
int findPassengerById(ePassenger lista[], int tam, int iD);


/**
 * \Brief remueve un pasajero por id y en su campo isEmpty se coloca el valor 1
 * \param lista de tipo struct
 * \param tam de tipo int tamaño de la lista
 * \param iD de tipo int
 *
 * \return retorna un -1 si no se pudo hacer nada en la funcion o el indice del lugar en donde esta el pasajero
 *
 */
int removePassenger(ePassenger lista[], int tam, int iD);


/**
 * \Brief muestra la informacion de un pasajero y no devuelve nada
 *
 * \retunr void
 *
 */
void printPassenger(ePassenger pasajero);


/**
 *
 *
 */
int printPassengers(ePassenger lista[], int tam);




















