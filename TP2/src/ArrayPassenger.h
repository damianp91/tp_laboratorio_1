#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


typedef struct{
	int iD;
	char description[20];

}eTypePass;


typedef struct{
	int iD;
	char descripcion[20];
}eStatus;


typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	eTypePass idPass;
	eStatus idFly;
	int isEmpty;

}ePassenger;


#endif /* ARRAYPASSENGER_H_ */


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
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tamTip de tipo int
 * \param estados array de tipo struct recibe lista de estados de vuelo
 * \param tam Esta tamTip de tipo int
 *
 * \return 0 en caso de no poder terminar con exito y 1 si se termina con exito la funcion
 *
 */
int addPassenger(ePassenger lista[], int tam, int* pId, char name[], char lastName[], float price, int typePassenger, char flyCode[], eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta);


/**
 * \Brief busca un pasajero por id y retorna el indice en donde se encuentra el mismo
 * \param lista de tipo struct
 * \param tam de tipo int tamaño de la lista
 * \param iD de tipo int
 *
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
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tamTip de tipo int
 * \param estados array de tipo struct recibe lista de estados de vuelo
 * \param tam Esta tamTip de tipo int
 *
 * \return retorna un -1 si no se pudo hacer nada en la funcion o el indice del lugar en donde esta el pasajero
 *
 */
int removePassenger(ePassenger lista[], int tam, int iD, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta);


/**
 * \Brief muestra la informacion de un pasajero y no devuelve nada
 * \param pasajero array de tipo struct recibe lista de pasajeros
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tamTip de tipo int
 * \param estados array de tipo struct recibe lista de estados de vuelo
 * \param tam Esta tamTip de tipo int
 *
 * \retunr void
 *
 */
void printPassenger(ePassenger pasajero, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta);


/**
 * \Brief imprime listado final de pasajeros con todos sus datos.
 * \param lista array de tipo struct recibe lista de pasajeros
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tamTip de tipo int
 * \param estados array de tipo struct recibe lista de estados de vuelo
 * \param tam Esta tamTip de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 *
 */
int printPassengers(ePassenger lista[], int tam, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta);


/**
 * \Brief reemplaza en lista el codigo de tipo de pasajero por su descripcion.
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tam de tipo int
 * \param iD de tipo int
 * \param descripcion de tipo char cadena de caracteres
 *
 * return 0 si no puede efectuar la funcion o 1 si pouede hacerlo
 *
 */
int pasajeIdTipo(eTypePass tipos[], int tam, int iD, char descripcion[]);


/**
 * \Brief reemplaza en lista el codigo de estado de vuelo por su descripcion.
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tam de tipo int
 * \param iD de tipo int
 * \param descripcion de tipo char cadena de caracteres
 *
 * return 0 si no puede efectuar la funcion o 1 si pouede hacerlo
 *
 */
int pasajeIdStatus(eStatus estados[], int tamEsta, int iD, char descripcion[]);


/**
 * \Brief permitr hacer cambios en algun campo de la entidad struct.
 * \param lista array de tipo struct recibe lista de pasajeros
 * \param tam de tipo int
 * \param tipos array de tipo struct recibe lista de tipos de pasajero
 * \param tamTip de tipo int
 * \param estados array de tipo struct recibe lista de estados de vuelo
 * \param tam Esta tamTip de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 */
int replaceFieldPassenger(ePassenger lista[], int tam, eTypePass tipos[], int tamTip, eStatus estados[], int tamEsta);


/**
 * \Brief permite ordenar una lista por apellido y tipo de pasajero segun el criterio que se asigne 1 up o 0 down
 * \param lista de tipo struct
 * \param tam de tipo int
 * \param criterio de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 */
int sortPassengers(ePassenger lista[], int tam, int criterio);



/**
 * \Brief permite ordenar una lista por destino y estado de vuelo segun el criterio que se asigne 1 up o 0 down
 * \param lista de tipo struct
 * \param tam de tipo int
 * \param criterio de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 */
int sortPassengersByCode(ePassenger lista[], int tam, int criterio);











