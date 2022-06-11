#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "r");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = parser_PassengerFromText(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = parser_PassengerFromBinary(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	Passenger* this;

	longitud = ll_len(pArrayListPassenger);
	printf("||===========================================================================================================================||\n"
			"||---[ID]---||----[NOMBRE]----||----[APELLIDO]----||--[PRECIO]--||--[CODIGO VUELO]--||--[TIPO PASAJERO]--||--[ESTADO VUELO]--||\n"
			"||===========================================================================================================================||\n");

	for (i = 0; i < longitud; i++)
	{
		this = (Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_list(this);
		printf("||===========================================================================================================================||\n");
	}


    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "w");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = SaveTxt(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "wb");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = SaveBinary(pFile, pArrayListPassenger);

	fclose(pFile);

	return validacion;
}

