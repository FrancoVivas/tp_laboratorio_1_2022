#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int calculateInterest(float num, float *result, float porcent)
{
    int retorno;
    retorno=1;
    if(result!=NULL)
    {
        *result= num - (num*porcent/100);
        retorno=0;
    }
    return retorno;
}
int calculateDescount(float num, float *result, float porcent)
{
    int retorno;
    retorno=1;
    if(result!=NULL)
    {
        *result= num + (num*porcent/100);
        retorno=0;
    }
    return retorno;
}
int calculatePriceBTC(float num, float *result)
{
    int retorno;
    int BTC;
    BTC = 4606954.55;
    retorno=1;
    if(result!=NULL)
    {
        *result= num/BTC;
        retorno=0;
    }
    return retorno;

}
int diferencePrices(float num1, float num2, float *result)
{
    int retorno;
    retorno=1;
    if(result != NULL)
    {
        *result=num1-num2;
        if(*result<0)
        {
            *result= -(*result);
        }

        retorno=0;
    }
    return retorno;

}

int getKilometro(float* pResult, char* message, char* messageError, float minimum, int retry)
{
	float bufferInt;
	int retorno;
	retorno=1;
	if(pResult != NULL && message != NULL && messageError != NULL && retry >=0 )
	{
		do
		{
			printf("%s", message);
			scanf("%f",&bufferInt);
			if(bufferInt > minimum)
			{
				*pResult = bufferInt;
				printf("Carga de datos exitoso.\n");
				retorno=0;
				system("pause");
				break;
			}
			else
			{
				printf("%s", messageError);
				retry--;
			}
		}while(retry>=0);
	}
	return retorno;
}

int maskMenu(int *option, float kilometer, float priceAero, float priceLatam)

{
	int retorno;
	int bufferOption;
	retorno=1;
	if(option!=NULL)
	{
		if(kilometer!=-1)
		{
			printf("1. Ingresar Kilometros. (Kilometros= %.2f) \n", kilometer);
		}
		else
		{
			printf("1. Ingresar Kilometros.\n");
		}
		if(priceAero!=-1 && priceLatam!=-1)
		{
			printf("2. Ingresar Precio de vuelos.(Aerolineas= %.2f, Latam= %.2f )\n",priceAero, priceLatam);
		}
		else if(priceAero!=-1 && priceLatam==-1)
		{
			printf("2. Ingresar Precio de vuelos.(Aerolineas= %.2f, Latam= *valor no ingresado* )\n",priceAero);
		}
		else if(priceAero==-1 && priceLatam!=-1)
		{
			printf("2. Ingresar Precio de vuelos.(Aerolineas= *valor no ingresado* , Latam= %.2f )\n", priceLatam);
		}
		else
		{
			printf("2. Ingresar Precio de vuelos.\n");
		}
		printf("3. Calcular todos los costos.\n");
		printf("4. Informar resultados.\n");
		printf("5. Carga forzada de datos.\n");
		printf("6. Salir.\n");
		printf("Elija una opcion: ");
		scanf("%d", &bufferOption);

		while(bufferOption<1||bufferOption>6)
		{
			system("CLS");
			if(kilometer!=-1)
			{
				printf("1. Ingresar Kilometros. (Kilometros= %.2f) \n", kilometer);
			}
			else
			{
				printf("1. Ingresar Kilometros.\n");
			}
			if(priceAero!=-1 && priceLatam!=-1)
			{
				printf("2. Ingresar Precio de vuelos.(Aerolineas= %.2f, Latam= %.2f )\n",priceAero, priceLatam);
			}
			else if(priceAero!=-1 && priceLatam==-1)
			{
				printf("2. Ingresar Precio de vuelos.(Aerolineas= %.2f, Latam= *valor no ingresado* )\n",priceAero);
			}
			else if(priceAero==-1 && priceLatam!=-1)
			{
				printf("2. Ingresar Precio de vuelos.(Aerolineas= *valor no ingresado* , Latam= %.2f )\n", priceLatam);
			}
			else
			{
				printf("2. Ingresar Precio de vuelos.\n");
			}
			printf("3. Calcular todos los costos.\n");
			printf("4. Informar resultados.\n");
			printf("5. Carga forzada de datos.\n");
			printf("6. Salir.\n");
			printf("Error elija una opcion correcta: ");
			scanf("%d", &bufferOption);
		}
		system("CLS");
		*option= bufferOption;
		retorno=0;
	}
	return retorno;
}

int getPriceAeroLatam(float *pResultAero, float *pResultLatam, char *messageAero,char *messageLatam, char *messageError , int tryAero, int tryLatam)
{
	int retorno;
	float bufferPriceAero;
	float bufferPriceLatam;
	retorno=1;
	if(pResultAero!=NULL && messageAero!=NULL && messageError!=NULL && pResultLatam!=NULL && messageLatam!=NULL)
	{
		printf("Solo tendra 2 intentos para cada entrada de datos. \n");
		system("pause");
		do
		{
			system("CLS");
			printf("%s", messageAero);
			scanf("%f", &bufferPriceAero);
			if(bufferPriceAero>=0)
			{
				*pResultAero = bufferPriceAero;
				printf("Carga de precio Aerolineas exitoso.\n");
				system("pause");
				break;
			}
			else
			{
				tryAero--;
				if(tryAero==0)
				{
					printf("Error, no se cargo los datos del precio Aerolineas.\n");
					system("pause");
				}
				else
				{
					printf("%s", messageError);
					system("pause");
				}
			}
		}while(tryAero>0);

		do
		{
			system("CLS");
			printf("%s", messageLatam);
			scanf("%f", &bufferPriceLatam);

			if(bufferPriceLatam>=0)
			{
				*pResultLatam = bufferPriceLatam;
				retorno=0;
				printf("Carga de precio Latam exitoso.\n");
				system("pause");
				break;
			}
			else
			{
				tryLatam--;
				if(tryLatam==0)
				{
					printf("Error, no se cargo los datos del precio Latam.\n");
					system("pause");
				}
				else
				{
					printf("%s", messageError);
					system("pause");
				}
			}
		}while(tryLatam>=0);


		retorno=0;
	}
	return retorno;
}

int validationIngress(float *kilometer, float *priceAero, float *priceLatam)
{
	int retorno;
	retorno=1;
	if(*kilometer==-1)
	{
		printf("Datos de kilometro no ingresados.\n");
		retorno=0;
	}
	if(*priceAero==-1)
	{
		printf("Datos de precio Aerolineas no ingresados.\n");
		retorno=0;
	}
	if(*priceLatam==-1)
	{
		printf("Datos de precio Latam no ingresados.\n");
		retorno=0;
	}
	return retorno;
}

void showResult(float kilometer, float priceAero, float priceLatam, float priceDebitAero, float priceDebitLatam, float priceCreditAero, float priceCreditLatam, float priceBTCAero, float priceBTCLatam, float priceKilometroAero, float priceKilometroLatam, float diferencePrice)
{
	if(priceAero != -1 && priceLatam != -1 && kilometer != -1)
	{
		printf("KMs Ingresados: %.2f km \n", kilometer);
		printf("Precio Aerolineas: $%.2f\n", priceAero);
		printf("a) Precio con tarjeta de debito: $ %.2f\n", priceDebitAero);
		printf("b) Precio con tarjeta de credito: $ %.2f\n", priceCreditAero);
		printf("c) Precio pagando con bitcoin: %.2f BTC\n", priceBTCAero);
		printf("d) Mostrar precio unitario: $ %.2f\n\n", priceKilometroAero);
		printf("Precio Latams: $%.2f\n", priceLatam);
		printf("a) Precio con tarjeta de debito: $ %.2f\n", priceDebitLatam);
		printf("b) Precio con tarjeta de credito: $ %.2f\n", priceCreditLatam);
		printf("c) Precio pagando con bitcoin: %.2f BTC\n", priceBTCLatam);
		printf("d) Mostrar precio unitario: $ %.2f\n\n", priceKilometroLatam);
		printf("La diferencia de precio es: $ %.2f\n", diferencePrice);

	}
	else
	{
		printf("Error, ingrese correctamente los datos de la opcion 1 y 2.\n");
	}

}

void showChargeForce()
{
	float enterKilometro;
	float priceFlightAero;
	float priceFlightLatam;
	float priceDebitAero;
	float priceDebitLatam;
	float priceCreditAero;
	float priceCreditLatam;
	float priceBTCAero;
	float priceBTCLatam;
	float priceKilometroAero;
	float priceKilometroLatam;
	float diferencePrice;
	enterKilometro= 7090;
	priceFlightAero= 162965;
	priceFlightLatam= 159339;

	calculateDescount(priceFlightAero, &priceDebitAero, 10);
	calculateDescount(priceFlightLatam, &priceDebitLatam, 10);
	calculateInterest(priceFlightAero, &priceCreditAero, 25);
	calculateInterest(priceFlightLatam, &priceCreditLatam, 25);
	calculatePriceBTC(priceFlightAero, &priceBTCAero);
	calculatePriceBTC(priceFlightLatam, &priceBTCLatam);
	priceKilometroAero = priceFlightAero/enterKilometro;
	priceKilometroLatam = priceFlightLatam/enterKilometro;
	diferencePrices(priceFlightAero,priceFlightLatam, &diferencePrice);

	printf("KMs Ingresados: %.2f km \n", enterKilometro);
	printf("Precio Aerolineas: $%.2f\n", priceFlightAero);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", priceDebitAero);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", priceCreditAero);
	printf("c) Precio pagando con bitcoin: %.2f BTC\n", priceBTCAero);
	printf("d) Mostrar precio unitario: $ %.2f\n\n", priceKilometroAero);
	printf("Precio Latams: $%.2f\n", priceFlightLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", priceDebitLatam);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", priceCreditLatam);
	printf("c) Precio pagando con bitcoin: %.2f BTC\n", priceBTCLatam);
	printf("d) Mostrar precio unitario: $ %.2f\n\n", priceKilometroLatam);
	printf("La diferencia de precio es: $ %.2f\n", diferencePrice);
	system("pause");
}
