#ifndef VALIDACIONES_C_
#define VALIDACIONES_C_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"
#include "validaciones.h"

#define TAM 51
#define MAX 5
//#define MIN 51

void validarOpcion (char opcion[], int tam, int *intOpcion){
	int validado;

	validado = validarEntero (opcion, tam);

	*intOpcion = validado;
}


void normalizarString (char nombreCompleto[], int tam){

	int i;

	for (i=0; i<tam; i++){
		nombreCompleto[0] = toupper (nombreCompleto[0]);
		if (nombreCompleto[i] == 32 ){
			nombreCompleto[i+1] = toupper (nombreCompleto[i+1]);
		}
	}
}
int validarString (char string [], int tam){
    setbuf(stdout, NULL);
    int i;
    int retorno;

    retorno = 1;
    for (i=0; i<strlen(string); i++){
        if (isalpha(string[i]) == 0 ){
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int GetIntNoVerification(char mensaje[], int* number){
	char numero[51];
	int retorno;
	retorno = 0;
	getString(mensaje, 51, numero);
	*number = atoi(numero);
	return retorno;
}
int validarEntero (char numero[], int tam) {
    setbuf(stdout, NULL);

    int i, nroVal;

    for (i=0; i< strlen(numero); i++){
        while( isdigit(numero[i]) == 0){
            printf("Error. Ingrese dato valido: ");
            fflush(stdin);
            scanf("%[^\n]", numero);
        }
    }
    nroVal = atoi (numero);

    return nroVal;
}
int validarRangoEntero (char mensaje[], int numeroIngresado, int min, int max){
		setbuf(stdout, NULL);
	while (numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}
	return numeroIngresado;
}
int GetIntWithRange(char mensaje[], char errorMsg[], int* number, int min, int max){
	char numero[51];
	int flagError;
	int retorno;
	retorno = -1;
	flagError = 1;
	getString(mensaje, 51, numero);
	*number = atoi(numero);
	if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
		flagError = 0;
		if(*number < min || *number > max){
			flagError = 1;
		}
	}
	while(flagError == 1){
		getString(errorMsg, 51, numero);
		*number = atoi(numero);
		if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
			flagError = 1;
			if(*number >= min && *number <= max){
				flagError = 0;
			}
		}
	}
	*number = atoi(numero);
	return retorno;
}

#endif /* VALIDACIONES_C_ */
