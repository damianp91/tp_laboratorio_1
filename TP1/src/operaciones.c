#include <stdio.h>
#include <stdlib.h>


int debitoDes10(float precio, float* pResultado){
	int retorno = 0;
	float porcentaje;

	if(precio >= 0 && pResultado != NULL){

		porcentaje = (10 * precio) / 100;
		*pResultado = precio - porcentaje;
		retorno = 1;

	}

	return retorno;
}


int creditoInte25(float precio, float* pResultado){
	int retorno = 0;
	float porcentaje;

	if(precio >= 0 && pResultado != NULL){

		porcentaje = (25 * precio) / 100;
		*pResultado = precio + porcentaje;
		retorno = 1;

	}

	return retorno;
}


int bitCoin(float precio, float* pResultado){
	int retorno = 0;
	float bit;

	if(precio >= 0 && pResultado != NULL){

		bit = precio / 4609731.71;
		*pResultado = bit;
		retorno = 1;

	}

	return retorno;
}


int preUnitario(float precio, float kilometros, float* pResultado){
	int retorno = 0;
	float unitario;

	if(precio >= 0 && pResultado != NULL){

		unitario = precio / kilometros;
		*pResultado = unitario;
		retorno = 1;

	}

	return retorno;
}
