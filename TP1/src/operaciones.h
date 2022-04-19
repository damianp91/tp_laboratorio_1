#ifndef OPERACIONES_H_
#define OPERACIONES_H_


/**
 * \brief Solicita un numero al usuario de tipo flotante para hacer un descuento del 10% al mismo, y devuelve un entero 0 si falla el ingreso
 * o 1 si se ingresa correctamente los datos.
 *
 * \param pResultado puntero float a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param precio de tipo float se pide a usuario para ejecutar la funcion.
 *
 *
 */
int debitoDes10(float precio, float* pResultado);


/**
 * \brief Solicita un numero al usuario de tipo flotante para hacer un aumento del 25% del mismo y devuelve un entero 0 si falla el ingreso
 * o 1 si se ingresa correctamente los datos.
 *
 * \param pResultado puntero float a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param precio de tipo float se pide a usuario para ejecutar la funcion.
 *
 *
 */
int creditoInte25(float precio, float* pResultado);


/**
 * \brief Solicita un numero al usuario de tipo flotante para hacer convercion de pesos a BICOIN y devuelve un entero 0 si falla el ingreso
 * o 1 si se ingresa correctamente los datos.
 *
 * \param pResultado puntero float a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param precio de tipo float se pide a usuario para ejecutar la funcion.
 *
 *
 */
int bitCoin(float precio, float* pResultado);


/**
 * \brief Solicita dos numeros al usuario de tipo flotante para calcular valor unitario por km el precio de vuelo y devuelve un entero 0 si falla el ingreso
 * o 1 si se ingresa correctamente los datos.
 *
 * \param pResultado puntero float a direccion de memoria de resultado que se envia si se ingresan los datos correctamente
 * \param precio de tipo float se pide a usuario para ejecutar la funcion.
 * \param kilometros de tipo int se pide a usuario para ejecutar la funcion.
 *
 *
 */
int preUnitario(float precio, int kilometros, float* pResultado);


#endif /* OPERACIONES_H_ */
