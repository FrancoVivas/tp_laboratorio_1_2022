#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int IngresarEntero (char mensaje[]);
int getInt(char mensaje[]);
int buscarEspacioLibre (Passenger list[], int tam, int* index);
void getString (char mensaje[], int tam, char string[]);
int GetFloatWithRange(char mensaje[], char errorMsg[], float* number, int min, int max);
int CheckIfNumber(char verifyArray[]);
int CountPeriodInString(char countArray[], int tam);
int CountMinusInString(char countArray[], int tam);
int CheckIfInt(char number[]);
void GetOption(char opcion[], int tam, int* intOpcion);

#endif /* FUNCIONES_H_ */
