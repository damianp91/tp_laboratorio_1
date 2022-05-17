#ifndef MENULISTAS_H_
#define MENULISTAS_H_


/**
 * \Brief funcion no recibe ningun parametro, pero devuelve un numero de tipo int de 1 a 5.
 * \param vacio.
 *
 */
int menuInicial();


/**
 * \Brief funcion no recibe ningun parametro, pero devuelve un numero de tipo int de 1 a 7.
 * \param vacio.
 *
 */
int subMenuPass();


/**
 * \Brief recibe dos parametros pero no devuelve nada, es un afuncion solo para imprimir una lista de tipo de pasajeros.
 * \param tipos de tipo struct.
 * \param tam de tipo int
 *
 */
void typePass(eTypePass tipos, int tam);


/**
 * \Brief recibe dos parametros que permiten desplegar un lista de tipos de pasajeros segun su tamanio
 * \param tipos de tipo struct.
 * \param tam de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 */
int listaTypePass(eTypePass tipos[], int tam);


/**
 * \Brief recibe dos parametros pero no devuelve nada, es un afuncion solo para imprimir una lista de estados de vuelos.
 * \param estados de tipo struct.
 * \param tam de tipo int
 *
 */
void statusPass(eStatus estados, int tam);


/**
 * \Brief recibe dos parametros que permiten desplegar un lista de estados de vuelos segun su tamanio
 * \param tipos de tipo struct.
 * \param tam de tipo int
 *
 * return retorna un 0 si no se pudo hacer nada en la funcion o 1 si se efectua con exito la funcion
 *
 */
int listaStatusPass(eStatus estados[], int tam);


#endif /* MENULISTAS_H_ */
