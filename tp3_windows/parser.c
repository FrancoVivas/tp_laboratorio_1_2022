#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int leido;
	char auxId[50];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[30];
	char auxCodigoVuelo[50];
	char auxTipoPasajero[50];
	char auxEstadoVuelo[50];
	Passenger* this;
	int validacion;

	validacion = 0;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("NO EXISTE EL ARCHIVO");
		exit(1);
	}

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", //FALSA LECTURA
					auxId,
					auxNombre,
					auxApellido,
					auxPrecio,
					auxCodigoVuelo,
					auxTipoPasajero,
					auxEstadoVuelo);

	while(!feof(pFile))
	{
		leido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
				auxId,
				auxNombre,
				auxApellido,
				auxPrecio,
				auxCodigoVuelo,
				auxTipoPasajero,
				auxEstadoVuelo);

		if (leido == 7)
		{
			this = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);
			ll_add(pArrayListPassenger, this);
			validacion = 1;
		}
	}
    return validacion;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int validacion;
	int leido;
	Passenger* this = NULL;

	validacion = 0;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("NO EXISTE EL ARCHIVO");
		exit(1);
	}

	while(!feof(pFile))
	{
		this = Passenger_new();

		leido = fread(this, sizeof(Passenger), 1, pFile);

		if (leido == 1)
		{
			if (feof(pFile))
			{
				break;
			}

			ll_add(pArrayListPassenger, this);
			validacion = 1;
			printf("LEDIO %d\n", leido);
		}
	}

    return validacion;
}
