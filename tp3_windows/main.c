#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int validacion = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do
    {
    	printf("||----< | [MENU] | >---||\n\n"

    			"[1] | CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO TEXTO)\n"
    			"[2] | CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO BINARIO)\n"
    			"[3] | CARGAR PASAJERO\n"
    			"[4] | MODIFICAR PASAJERO\n"
    			"[5] | ELIMINAR PASAJERO\n"
    			"[6] | LISTAR PASAJERO\n"
    			"[7] | ORDENAR PASAJEROS\n"
    			"[8] | GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO TEXTO)\n"
    			"[9] | GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO BINARIO)\n\n"

    			"||--->[INGRESAR OPCION]:");

    			fflush(stdin);
    			scanf("%d", &option);

        switch(option)
        {
            case 1:

            	if (ll_isEmpty(listaPasajeros))
            	{
            		validacion = controller_loadFromText("data.csv",listaPasajeros);

					if (validacion == 1)
					{
						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
						system("pause");
					}
					else
					{
						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
						system("pause");
					}
            	}
            	else
            	{
            		printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
					system("pause");
            	}
			break;

            case 2:
            	if (ll_isEmpty(listaPasajeros))
				{
					validacion = controller_loadFromBinary("data.bin",listaPasajeros);

					if (validacion == 1)
					{
						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
						system("pause");
					}
					else
					{
						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
						system("pause");
					}
				}
				else
				{
					printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 6:
            	controller_ListPassenger(listaPasajeros);
			break;

            case 8:
            	validacion = controller_saveAsText("data.csv", listaPasajeros);

            	if (validacion == 1)
				{
					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
					system("pause");
				}
				else
				{
					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
					system("pause");
				}
			break;

            case 9:
            	validacion = controller_saveAsBinary("data.bin", listaPasajeros);

            	if (validacion == 1)
				{
					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
					system("pause");
				}
				else
				{
					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
					system("pause");
				}
			break;
        }
    }while(option != 10);

    return 0;
}

