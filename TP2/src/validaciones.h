#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

void normalizarString (char [], int);

int validarRangoEntero (char [], int , int, int);

int verificarParidad (int);

int validarIngresoEntero (char [], int );

int validarString (char string [], int tam);
int GetIntNoVerification(char mensaje[], int* number);
int validarEntero (char numero[], int tam);
void validarOpcion (char opcion[], int tam, int *intOpcion);
int validarRangoEntero (char mensaje[], int numeroIngresado, int MIN, int MAX);
int GetIntWithRange(char mensaje[], char errorMsg[], int* number, int min, int max);
#endif /* VALIDACIONES_H_ */
