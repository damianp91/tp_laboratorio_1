#ifndef UTN_H_
#define UTN_H_


/**
 * \brief Solicita un numero al usuario de tipo entero y devuelve un entero 0 si falla el ingreso o 1 si se ingresa correctamente los datos.
 * \param pResultado puntero int a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param pMensaje puntero char de mensaje seleccionado para dar ingreso a datos.
 * \param pMensError puntero char a mensaje por si falla el ingreso de datos
 * \param min tipo int indica el valor minimo de ingreso
 * \param max tipo int indica el valor maximo de ingreso
 *
 */
int get_NumEnte(int* pResultado, char* pMensaje, char* pMensError, int min, int max);

/**
 * \brief Solicita un numero al usuario de tipo flotante y devuelve un entero 0 si falla el ingreso o 1 si se ingresa correctamente los datos.
 * \param pResultado puntero float a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param pMensaje puntero char de mensaje seleccionado para dar ingreso a datos.
 * \param pMensError puntero char a mensaje por si falla el ingreso de datos
 * \param min tipo int indca el valor minimo de ingreso
 * \param max tipo int indica el valor maximo de ingreso
 *
 */
int get_NumFlota(float* pResultado, char* pMensaje, char* pMensError, float min, float max);

/**
 * \brief Solicita una cadena de caracter al usuario de tipo char y devuelve un entero 0 si falla el ingreso o 1 si se ingresa correctamente los datos.
 * \param pResultado puntero char a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param pMensaje puntero char de mensaje seleccionado para dar ingreso a datos.
 * \param pMensError puntero a mensale por si falla el ingreso de datos
 * \param min tipo char indca el valor minimo de ingreso ASCII
 * \param max tipo char indica el valor maximo de ingreso ASCII
 *
 */
int get_Caracter(char* pResultado, char* pMensaje, char* pMensError, char min, char max);

#endif /* UTN_H_ */
