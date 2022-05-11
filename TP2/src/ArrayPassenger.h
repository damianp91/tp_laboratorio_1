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











