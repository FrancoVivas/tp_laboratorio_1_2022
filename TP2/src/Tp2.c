#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "funciones.h"
#include "validaciones.h"

int main(void) {

		setbuf(stdout, NULL);

	Passenger listaPassengers [QTYPASS];

	initPassengers (listaPassengers, QTYPASS);

	char opcion[TAM];
	int flagInitPass;
	int flagEmptyMsg;
	int intOpcion;
	int removeById;
	int cantidadPass;

	flagEmptyMsg = 1;

	cantidadPass = 0;

	do
	{
		EmptySpaces (listaPassengers, QTYPASS, &flagInitPass);

		if(flagInitPass == VACIO && flagEmptyMsg == 1){
			printf(">>> La lista esta vacia. <<<\n");
			//flagEmptyMsg = 0;
		}

		printf("_________________________\n"
			   "1| ALTA empleado. %8s\n"
			   "2| MODIFICAR empleado. %3s\n"
			   "3| BAJA empleado. %8s\n"
			   "4| INFORMAR (Submenu). %3s\n"
		       "5| CARGA FORZADA. %8s\n"
			   "0| Salir. %16s\n"
			   "_|_______________________|\n", "|", "|", "|", "|", "|", "|");

		GetOption(opcion, TAM, &intOpcion);
		while(intOpcion < 0 || intOpcion > 5){
			printf(">>> Error. Ingrese un numero valido.\n");
			GetOption(opcion, TAM, &intOpcion);
		}
		printf("\n");

		while (intOpcion< 0|| intOpcion > 5){
			printf("Error! Ingrese opcion valida... :");
			fflush(stdin);
			scanf("%d", &intOpcion);
		}

		if(intOpcion == 5){
			flagInitPass = CARGADO;
			flagEmptyMsg = 0;

		}
		if(flagInitPass == 0 && intOpcion != 0 && intOpcion != 1){
			printf(">>> La lista esta vacia.\n");
			flagEmptyMsg= 0;
		}
		else{
			switch(intOpcion){
				case 1: //ALTA
					if(getPassenger(listaPassengers, QTYPASS, &cantidadPass) != 0){
						printf(">>> Error. La lista ya esta llena. \n");
					}
				break;

				case 2: //MODIFICAR
					if(ModifyPassenger(listaPassengers, QTYPASS, TAM) == -1){
						printf(">>> Ocurrio un error inesperado.\n");
					}
				break;

				case 3: //BAJA
					printPassengers(listaPassengers, QTYPASS);
					GetIntNoVerification(">>> Ingrese el ID a eliminar: ", &removeById);
					if(removePassenger(listaPassengers, QTYPASS, removeById) == 0){
						printf(">>> Se elimino el pasajero con exito.\n");
					}
				break;

				case 4: //INFORMAR
					printf(">>> Submenu INFORMAR.\n");
					InformSubMenu(listaPassengers, QTYPASS, TAM, &intOpcion);
				break;
				case 5: //CARGA FORZADA
					cargaForzada (listaPassengers, QTYPASS);
				break;
				case 0: //SALIR
					printf("Fin del programa. ");
				break;
			}
		}



	}while(intOpcion != SALIR);


	return EXIT_SUCCESS;
}
}

