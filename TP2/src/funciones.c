#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"
#include "validaciones.h"


int getInt(char mensaje[]){
		setbuf(stdout, NULL);
	int numero;

	printf(mensaje);
	fflush(stdin);
	scanf("%d", &numero);

	return numero;
}
void getString (char mensaje[], int tam, char string[]){ // acá
	setbuf(stdout, NULL);

	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]s", string);

}
int buscarEspacioLibre (Passenger list[], int tam, int* index){

	int rtn;
    *index = -1;

    if(list != NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
           if(list[i].isEmpty == VACIO)
           {
               *index = i;
               rtn = 0;
               break;
           }
        }
    }


	return rtn;
}



float getFloat(char mensaje []){
		setbuf(stdout, NULL);

	float valor;

	printf(mensaje);
	fflush(stdin);
	scanf("%f", &valor);

	return valor;
}
int GetFloatWithRange(char mensaje[], char errorMsg[], float* number, int min, int max){
	char numero[51];
	int flagError;
	int retorno;
	retorno = -1;
	flagError = 1;
	getString(mensaje, 51, numero);
	*number = atof(numero);
	if(CheckIfNumber(numero) == 1){
		flagError = 0;
		if(*number < min || *number > max){
			flagError = 1;
		}
	}
	while(flagError == 1){
		printf("Error! Valor invalido. ");
		getString(mensaje, 51, numero);
		*number = atof(numero);
		if(CheckIfNumber(numero) == 1){
			flagError = 1;
			if(*number >= min && *number <= max){
				flagError = 0;
			}
		}
	}
	*number = atof(numero);
	return retorno;
}
int CheckIfNumber(char verifyArray[]){
	int retorno;
	int contPuntos;
	int contMenos;
	retorno = 1;

	contPuntos = CountPeriodInString(verifyArray, strlen(verifyArray));
	contMenos = CountMinusInString(verifyArray, strlen(verifyArray));

	for(int i = 0; verifyArray[i] != '\0'; i++){
		if(verifyArray[i] < '-' || (verifyArray[i] > '.' && verifyArray[i] < '0') || verifyArray[i] > '9'){
			retorno = 0;
			break;
		} else {
			if(contMenos > 0 || contPuntos > 1 || (verifyArray[0] == '-' && verifyArray[1] == '.') || verifyArray[0] == '.' || (strlen(verifyArray) == 1 && verifyArray[0] == '-')){                     //
				retorno = 0;
				break;
			}
		}
	}
	if(strlen(verifyArray) == 0){
		retorno = 0;
	}
	return retorno;
}
int CheckIfInt(char number[]){
	int retorno;
	int largo;
	retorno = 0;
	largo = strlen(number);
	for(int i = 0; i < largo; i++){
		if(number[i] == '.'){
			retorno = -1;
			break;
		}
	}
	return retorno;
}
int CountPeriodInString(char countArray[], int tam){
	int contPuntos = 0;
	int i;
	for(i = 0; i < tam; i++){
		if(countArray[i] == '.'){
			contPuntos++;
		}
	}
	return contPuntos;
}
int CountMinusInString(char countArray[], int tam){
	int contNegativos = 0;
	int i;
	for(i = 1; i < tam; i++){
		if(countArray[i] == '-'){
			contNegativos++;
		}
	}
	return contNegativos;
}
void GetOption(char opcion[], int tam, int* intOpcion){

	getString("Ingrese una opcion: ", tam, opcion);
	*intOpcion = atoi(opcion);
	if(CheckIfNumber(opcion) == 1){
		*intOpcion = -1;
		if(CheckIfInt(opcion) == 0){
			*intOpcion = atoi(opcion);
		}
	} else {
		*intOpcion = -1;
	}
}
