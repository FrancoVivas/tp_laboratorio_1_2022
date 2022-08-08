#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"
#include "validaciones.h"

static int idIncrementalPass = 1000;
static int obtenerID();

static int obtenerID(){
	return idIncrementalPass++;
}

void cargaForzada (Passenger list[], int tam){

	Passenger listaHardcode [5] = {{1010, "Sebastian", "Sartorato", 65000, "E5000", MENOR, DEMORADO, CARGADO},{1011, "Manuel", "Jimenez", 13830, "E5100", ADULTO ,ACTIVO, CARGADO},{1012, "Juan", "Gonzalez", 72345, "E5430" , MENOR , DEMORADO, CARGADO},{1013, "Julian", "Fernandez", 29376, "E5345", ADULTO , DEMORADO, CARGADO},{1014, "Sofia", "Diaz", 53742,"E5600", MENOR ,DEMORADO, CARGADO}};


	for (int i = 0; i<tam-1; i++){
		for (int j = i+1; i<tam; j++){
			list[j].id = listaHardcode[i].id;
			strcpy(list[j].name, listaHardcode[i].name);
			strcpy(list[j].lastName, listaHardcode[i].lastName);
			list[j].price = listaHardcode[i].price;
			strcpy(list[j].flycode, listaHardcode[i].flycode);
			list[j].typePassenger = listaHardcode[i].typePassenger;
			list[j].statusFlight = listaHardcode[i].statusFlight;
			list[j].isEmpty = listaHardcode[i].isEmpty;
		}
	}
}
int getPassenger (Passenger lista[], int tam, int* cantidadPass){
	setbuf(stdout, NULL);
	int rtn;
	int id;
	int typePassenger;
	int statusFlight;
	float price;
	char name [51];
	char lastName [51];
	char flycode [10];
	int dia;
	int mes;
	int anio;

	rtn = -1;


	if(lista != NULL && tam!=0){

		getString("Ingrese su nombre: ", 51, name);
		while (validarString (name, 51) == 0){
			getString("Error. Ingrese el nombre correctamente: ", 51, name);
		}

		getString("Ingrese su apellido: ", 51, lastName);
		while (validarString (lastName, 51) == 0){
			getString("Error. Ingrese el apellido correctamente: ", 51, lastName);
		}

		getString("Ingrese el codigo del vuelo: ", 51, flycode);

		GetFloatWithRange(">>> Ingrese el precio (5000-85000): ", "Precio invalido ", &price, 5000, 85000);

		GetIntWithRange("Ingrese el dia: ", "Error, ingrese dia valido: ", &dia, 1, 31);
		GetIntWithRange("Ingrese el mes: ", "Error, ingrese el mes valido: ", &mes, 1, 12);
		GetIntWithRange("Ingrese el anio: ", "Error, ingrese anio valido: ", &anio, 2022, 2023);



		id = obtenerID ();

		typePassenger = getTypePassenger();
		statusFlight = getStatusFlight();

		rtn = 0;

		if (addPassenger(lista, tam, statusFlight, id, name, lastName, price, typePassenger, flycode, dia, mes, anio) == -1){
			rtn= 1;
		}
	}

	if (rtn == 0){
		printf("Se añadio correctamente el pasajero... \n");
		cantidadPass++;
	}

	return rtn;
}
void InformSubMenu(Passenger list[], int len, int tam, int* mainMenuOption){
	char opcion[tam];
	int intOpcion;

	printf("1| MOSTRAR pasajeros alfabeticamente. \n");
	printf("2| INFORMAR promedio de precios. \n");
	printf("3| MOSTRAR listado por codigo vuelo y activos. \n");
	printf("9| Main Menu. \n");
	printf("0| Salir. \n");


	GetOption(opcion, tam, &intOpcion); // ver get option
	while(intOpcion < 0 || (intOpcion > 3 && intOpcion != 9)){
		printf(">>> Error. Ingrese un numero valido.\n");
		GetOption(opcion, tam, &intOpcion);
	}
	printf("\n");

	switch (intOpcion){
		case 1:
			if(sortPassengers(list, len, 0) == -1){
				printf(">>> Ocurrio un error inesperado.\n");
			}
			printPassengers(list, len);
		break;

		case 2:
			if(AveragePrices(list, len) == -1){
				printf(">>> Ocurrio un error inesperado.\n");
			}
		break;
		case 3:
			printPassengerActive (list, len);
		break;
		case 9:
			printf(">>> Menu PRINCIPAL.\n");
		break;

		case 0:
			*mainMenuOption = 0;
		break;
	}
}
int AveragePrices(Passenger list[], int len){
	int retorno;
	float acumPrices;
	int countPassengers;
	float averagePrices;
	int countAveragePricePassenger;
	countAveragePricePassenger = 0;
	countPassengers = 0;
	acumPrices = 0;
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				countPassengers++;
				acumPrices += list[i].price;
			}
		}
		averagePrices = acumPrices / countPassengers;
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				if(list[i].price > averagePrices){
					countAveragePricePassenger++;
				}
			}
		}
	}
	if(retorno == 0){
		printf(">>> Pasajeros: %d\n"
			   ">>> Suma de todos los precios: %.2f\n"
			   ">>> Precio promedio: %.2f\n"
			   ">>> Pasajeros que lo superan: %d\n", countPassengers, acumPrices, averagePrices,countAveragePricePassenger);
	}
	return retorno;
}
int sortPassengers(Passenger list[], int len, int order){
	int retorno;
	char ordenamiento[51];
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 1;
		order = GetOrder(ordenamiento, 51);
		if(order == ATOZ){
			retorno = 0;
			SortAtoZ(list, len);
		} else {
			if(order == ZTOA){
				SortZtoA(list, len);
				retorno = 0;
			}
		}
	}
	return retorno;
}
int GetOrder(char order[], int len){
	int ordenamiento;
	int countRetries;
	countRetries = 0;
	ordenamiento = -1;
	printf(">>> (Ascendente / Descendente)\n");
	getString(">>> Ingrese el ordenamiento: ", len, order);
	while(stricmp(order, "ascendente") != 0 && stricmp(order, "descendente") != 0){
		getString(">>> Error, ingrese un ordenamiento valido: ", len, order);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Ascendente / Descendente)\n");
			countRetries = 0;
		}
	}
	if(stricmp(order, "ascendente") == 0){
		ordenamiento = ATOZ;
	} else {
		if(stricmp(order, "descendente") == 0){
			ordenamiento = ZTOA;
		}
	}
	return ordenamiento;
}
void SortAtoZ(Passenger list[], int len){
	Passenger temp;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 1){
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 0){
				if(list[i].typePassenger > list[j].typePassenger){
					temp = list[j];
					list[j] = list[i];
					list[i] = temp;
				}
			}
		}
	}
	printf(">>> Se ordeno de forma ascendente.\n");
}
void SortZtoA(Passenger list[], int len){
	Passenger temp;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == -1){
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 0){
				if(list[i].typePassenger < list[j].typePassenger){
					temp = list[j];
					list[j] = list[i];
					list[i] = temp;
				}
			}
		}
	}
	printf(">>> Se ordeno de forma descendente.\n");
}

int addPassenger (Passenger list[], int len, int statusFlight, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int dia, int mes, int anio){

	int rtn;
	int i;

	rtn = buscarEspacioLibre (list, len, &i);

	if(list !=NULL && len >0 && name != NULL && lastName != NULL){
		if (rtn== 0){
			list[i].id = id;
			list[i].isEmpty = CARGADO;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flycode, flycode);
			list[i].statusFlight = statusFlight;
			list[i].fecha.dia = dia;
			list[i].fecha.mes = mes;
			list[i].fecha.anio = anio;
		}
	}

	return rtn;
}

int findPassengerById (Passenger list[], int len, int id){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty == CARGADO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int ModifyPassenger (Passenger list[], int len, int tam){
	float price;
	char name[tam];
	char lastName[tam];
	char flycode[10];
	int typePassenger;
	int dataToModify;
	int retorno;
	int index;
	int id;

	retorno = -1;
	if(list != NULL && len > 0){
		//SortById(list, len);
		printPassengers(list, len);

		GetIntNoVerification(">>> Ingrese el ID del pasajero a modificar: ", &id);

		if(findPassengerById(list, len, id) == -1){
			index = GetOccupiedId(list, len);
		}
		else{
			index = findPassengerById(list, len, id);
		}
		dataToModify = GetDataToModify();

		switch(dataToModify){
			case NAME:
				getString(">>> Ingrese el nuevo nombre: ", tam, name);
				while(validarString(name, 51) == 0){
					printf(">>> Error, nombre invalido. ");
					getString("Reingrese un nombre: ", tam, name);
				}
				//SortName(name);
				strcpy(list[index].name, name);
			break;

			case LASTNAME:
				getString(">>> Ingrese el nuevo apellido: ", tam, lastName);
				while(validarString(lastName, 51) == 0){
					printf(">>> Error, apellido invaildo. ");
					getString("Reingrese un apellido: ", tam, lastName);
				}
				//SortName(lastName);
				strcpy(list[index].lastName, lastName);
			break;

			case PRICE:
				GetFloatWithRange(">>> Ingrese el nuevo precio (5000-85000): ", ">>> Precio invalido, reingrese un precio (5000-85000): ", &price, 5000, 85000);
				list[index].price = price;
			break;

			case TYPEPASS:
				typePassenger = getTypePassenger();
				list[index].typePassenger = typePassenger;
			break;

			case FLYCODE:
				getString("Ingrese el codigo del vuelo: ", 51, flycode);
				strcpy(list[index].flycode, flycode);
			break;
		}
		retorno = 0;
	}
	if(retorno == 0){
		printf(">>> Se modificó la lista de forma exitosa.\n");
	}
	return retorno;
}
int GetDataToModify(){
	int dataToChange;
	int countRetries;
	char modification[51];
	countRetries = 0;
	dataToChange = -1;
	printf(">>> (Nombre / Apellido / Precio / Tipo Pasajero / Codigo Vuelo)\n");
	getString(">>> Ingrese que dato desea modificar: ", 51, modification);
	while(stricmp(modification, "nombre") != 0 && stricmp(modification, "apellido") != 0 && stricmp(modification, "precio") != 0 && stricmp(modification, "tipo pasajero") != 0 && stricmp(modification, "codigo vuelo") != 0){
		getString(">>> Error, ingrese un dato valido: ", 51, modification);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Nombre / Apellido / Precio / Tipo Pasajero / Codigo Vuelo)\n");
			countRetries = 0;
		}
	}
	if(stricmp(modification, "nombre") == 0){
		dataToChange = NAME;
	}
	else {
		if(stricmp(modification, "apellido") == 0){
			dataToChange = LASTNAME;
		}
		else {
		 if(stricmp(modification, "precio") == 0){
			 dataToChange = PRICE;
		 }
		 else{
			if(stricmp(modification, "tipo pasajero") == 0){
				dataToChange = TYPEPASS;
			}
			else{
				if(stricmp(modification, "codigo vuelo") == 0){
					dataToChange = FLYCODE;
				}
				else{
					dataToChange = -1;
				}
			}
		}
		}

	}
	return dataToChange;
}

int GetOccupiedId(Passenger list[], int len){
	int index;
	int countRetries;
	int id;
	index = -1;
	countRetries = 0;
	while(index == -1){
		GetIntNoVerification(">>> Error, se ingresó un ID invalido: ", &id);
		countRetries++;
		if(countRetries == 6){
			printPassengers(list, len);
			countRetries = 0;
		}
		index = findPassengerById(list, len, id);
	}
	return index;
}

int removePassenger(Passenger list[], int len, int id){
	int rtn;
	int index;
	rtn = -1;
	index = findPassengerById(list, len, id);
	if(list != NULL && len > 0){
		if(findPassengerById(list, len, id) == -1){
			index = GetOccupiedId(list, len);
		}
		list[index].isEmpty = VACIO;
		rtn = 0;
	}
	return rtn;
}

int printPassengers(Passenger list[], int len){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		TopPartChart();
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				printOnePassenger(list[i]);
				printf("\n");
			}
		}
		BottomPartChart();
	}
	return retorno;
}
void printPassengerActive (Passenger list[], int len){

	printf(">>> Pasajeros con vuelo Activo: \n");
	if(list!=NULL && len >0){
		for (int i = 0; i<len; i++){
			if(list[i].isEmpty == CARGADO){
				if (list[i].statusFlight == ACTIVO ){
					printf("%-5s | %-20s | %-15s \n", list[i].flycode, list[i].lastName, list[i].name);
				}
			}
		}
	}
}
int printOnePassenger(Passenger list){
	int retorno;
	retorno = 0;
	printf("| %-5d | %-20s | %-15s | %-15.2f | ", list.id, list.lastName, list.name, list.price);

	switch(list.statusFlight){
		case DEMORADO:
			printf("%-20s |", "Demorado");
		break;
		case CANCELADO:
			printf("%-20s |", "Cancelado");
		break;
		case ATERRIZADO:
			printf("%-20s |", "Aterrizado");
		break;
		case ACTIVO:
			printf("%-20s |", "Activo");
		break;
	}
	return retorno;
}
void TopPartChart(){
	printf(" _________________________________________________________________________________________\n");
	printf("| %-5s | %-20s | %-15s | %-15s | %-20s |\n", "ID", "Apellido", "Nombre", "Precio", "Estado");
	printf("|-------|----------------------|-----------------|-----------------|----------------------|\n");
}
void BottomPartChart(){
	printf("|_______|______________________|_________________|_________________|______________________|\n");
}
int getStatusFlight (){
	char typeStatusPassenger [51];
	int typeStatus;
	int countRetries;

	countRetries = 0;
	typeStatus = -1;
	printf(">>> (Demorado / Cancelado / Aterrizado / Activo ) <<<\n");
	getString(">>> Ingrese el estado de vuelo: ", 51, typeStatusPassenger);
		while(stricmp(typeStatusPassenger, "demorado") != 0 && stricmp(typeStatusPassenger, "cancelado") != 0 && stricmp(typeStatusPassenger, "aterrizado") != 0 && stricmp(typeStatusPassenger, "activo") != 0){
			getString(">>> Error, ingrese un estado valido: ", 51, typeStatusPassenger);
			countRetries++;
			if(countRetries == 5){
				printf(">>> (Demorado / Cancelado / Aterrizado / Activo ) <<<\n");
				countRetries = 0;
			}
		}
		if(stricmp(typeStatusPassenger, "demorado") == 0){
			typeStatus = DEMORADO;
		}
		else {
			if(stricmp(typeStatusPassenger, "cancelado") == 0){
				typeStatus = CANCELADO;
			}
			else{
				if(stricmp(typeStatusPassenger, "aterrizado") == 0){
					typeStatus = ATERRIZADO;
				}
				else{
					if(stricmp(typeStatusPassenger, "activo") == 0){
						typeStatus = ACTIVO;
					}
				}
			}
		}

	return typeStatus;
}
int getTypePassenger(){
	char typePassenger[51];
	int typeNumber;
	int countRetries;

	countRetries = 0;
	typeNumber = -1;
	printf(">>> (Adulto / Menor)\n");
	getString(">>> Ingrese el tipo de pasajero: ", 51, typePassenger);
	while(stricmp(typePassenger, "adulto") != 0 && stricmp(typePassenger, "menor") != 0){
		getString(">>> Error, ingrese un tipo valido: ", 51, typePassenger);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Adulto / Menor)\n");
			countRetries = 0;
		}
	}
	if(stricmp(typePassenger, "adulto") == 0){
		typeNumber = ADULTO;
	}
	else {
		if(stricmp(typePassenger, "menor") == 0){
			typeNumber = MENOR;
		}
	}


	return typeNumber;
}
int initPassengers(Passenger list [], int len){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty != CARGADO){    // <---- SI LA LISTA YA ESTA CARGADA.
				list[i].isEmpty = VACIO;
				retorno = 0;
			}
		}
	}
	return retorno;
}

void EmptySpaces (Passenger lista[], int tam, int* flagInitPass){

	int contEmpty;
	int i;
	contEmpty = 0;
	*flagInitPass = CARGADO;

	for(i = 0; i < tam; i++){
		if(lista[i].isEmpty == VACIO){
			contEmpty++;
		}
	}
	if(contEmpty == tam){
		*flagInitPass = VACIO;
	}
}
