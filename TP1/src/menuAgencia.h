#ifndef MENUAGENCIA_H_
#define MENUAGENCIA_H_


/**
 * \brief menu de opciones funcion sin ingreso de datos pero que devuelve un int segun opcion seleccionada
 * \param km de tipo float.
 * \param empre1 de tipo float
 * \param empre1 de tipo float
 *
 *
 */
int menu(float km, float empre1, float empre2);


/**
 * \brief informe de calculos realizados por el programa.
 * \param pMensaje de tipo puntero char mensaje que se envia desde la función.
 * \param empresa de tipo float
 * \param debito de tipo float
 * \param credito de tipo float
 * \param bitCoin de tipo float
 * \param unitario de tipo float
 *
 *
 */
void informe(char* pMensaje, float empresa, float debito, float credito, float bitCoin, float unitario);

#endif /* MENUAGENCIA_H_ */
