/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"


Passenger* Passenger_new()
{
	Passenger* this;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{
	Passenger* this;
	int id;
	float precio;
	int tipoPasajero;

	this = Passenger_new(); //ASIGNAMOS ESPACIO EN MEMORIA DINAMICA.

	id = atoi(idStr);

	precio = atof(precioStr);

	if (strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if (strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}
	if (this != NULL)
	{
		if(Passenger_setId(this, id) == 0 ||
		   Passenger_setNombre(this, nombreStr) == 0||
		   Passenger_setApellido(this, apellidoStr) == 0||
		   Passenger_setPrecio(this, precio) == 0||
		   Passenger_setTipoPasajero(this, tipoPasajero) == 0||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == 0||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == 0)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}

//-------------------------------- [ID] --------------------------------------
int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [NOMBRE] --------------------------------------
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [APELLIDO] --------------------------------------
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [CODIGO DE VUELO] --------------------------------------
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [TIPO DE PASAJERO] --------------------------------------
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [PRECIO] --------------------------------------
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [ESTADO DE VUELO] --------------------------------------
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}

	return retorno;
}
//-------------------------------- [BORRAR PASAJERO] --------------------------------------
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}
//-------------------------------- [LISTAR UN PASAJERO] --------------------------------------
void Passenger_list(Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[40];

	char tipoPasajeroStr[20];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getTipoPasajero(this, &tipoPasajero);
	Passenger_getEstadoVuelo(this, estadoVuelo);

	if (tipoPasajero == 1)
	{
		strcpy(tipoPasajeroStr, "FirstClass");
	}
	else
	{
		if (tipoPasajero == 2)
		{
			strcpy(tipoPasajeroStr, "ExecutiveClass");
		}
		else
		{
			strcpy(tipoPasajeroStr, "EconomyClass");
		}
	}

	printf("||%-10d||%-16s||%-18s||%-12.2f||%-18s||%-19s||%-18s||\n",
			id,
			nombre,
			apellido,
			precio,
			codigoVuelo,
			tipoPasajeroStr,
			estadoVuelo);
}

int SaveTxt(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[8];
	char auxEstadoVuelo[40];
	int validacion;

	validacion = 0;

	Passenger* this;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("[ERROR] - NO EXISTE EL ARCHIVO");
		exit(1);
	}

	longitud = ll_len(pArrayListPassenger);

	if (longitud > 0)
	{
		fprintf(pFile, "ID,NOMBRE,APELLIDO,PRECIO,CODIGOVUELO,TIPOPASAJERO,ESTADOVUELO\n");

		for(i = 0; i < longitud; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			if (this != NULL)
			{
				Passenger_getId(this, &auxId);
				Passenger_getNombre(this, auxNombre);
				Passenger_getApellido(this, auxApellido);
				Passenger_getPrecio(this, &auxPrecio);
				Passenger_getCodigoVuelo(this, auxCodigoVuelo);
				Passenger_getEstadoVuelo(this, auxEstadoVuelo);

				fprintf(pFile, "%d,%s,%s,%f,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxEstadoVuelo);

				validacion = 1;
			}
		}
	}

	return validacion;
}

int SaveBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	int validacion;

	validacion = 0;

	Passenger* this;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("[ERROR] - NO EXISTE EL ARCHIVO");
		exit(1);
	}

	longitud = ll_len(pArrayListPassenger);

	if (longitud > 0)
	{
		for(i = 0; i < longitud; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			if (this != NULL)
			{
				fwrite(this, sizeof(Passenger), 1, pFile);

				validacion = 1;
			}
		}
	}

	return validacion;
}
