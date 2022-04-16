#include <stdio.h>
#include <stdlib.h>


int get_NumEnte(int* pResultado, char* pMensaje, char* pMensError, int min, int max){
	int retorno = 0;
	int numero;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		prinf("%s", pMensaje);
		scanf("%d", &numero);

		if(numero >= min && numero <= max){
			*pResultado = numero;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;
}


int get_NumFlota(float* pResultado, char* pMensaje, char* pMensError, float min, float max){
	int retorno = 0;
	float numero;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		prinf("%s", pMensaje);
		scanf("%f", &numero);

		if(numero >= min && numero <= max){
			*pResultado = numero;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;

}


int get_Caracter(char* pResultado, char* pMensaje, char* pMensError, char min, char max){
	int retorno = 0;
	char caracter;
	if(pResultado != NULL && pMensaje != NULL && pMensError != NULL && min <= max){

		prinf("%s", pMensaje);
		fflush(stdin);
		scanf("%d", &caracter);

		if(caracter >= min && caracter <= max){
			*pResultado = caracter;
			retorno = 1;
		}
		else{
			printf("%s", pMensError);
		}

	}

	return retorno;
}























