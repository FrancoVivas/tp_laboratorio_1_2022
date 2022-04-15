#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main()
{
    setbuf(stdout, NULL);
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
	int validation;
	int optionMenu;
	int flag;
	flag=0;//bandera para saber si se calculo correctamente todos los datos en la opcion 3
	enterKilometro=-1;//Inicializo para saber si ingreso o no un numero
	priceFlightAero=-1;//Inicializo para saber si ingreso o no un numero
	priceFlightLatam=-1;//Inicializo para saber si ingreso o no un numero
	do{
		system("CLS");
		maskMenu(&optionMenu, enterKilometro, priceFlightAero, priceFlightLatam);
		switch(optionMenu)
		{
			case 1:
				getKilometro(&enterKilometro,"Ingrese los Kilometros: \n", "Error, ingrese un dato valido en Kilometros:\n", 0 ,2 );
				break;
			case 2:
				getPriceAeroLatam(&priceFlightAero, &priceFlightLatam,"Ingrese precio de vuelo Aerolineas: \n", "Ingrese precio de vuelo Latam: \n", "Error, ingrese correctamente el precio.\n",2,2);
				break;
			case 3:
			    validation=validationIngress(&enterKilometro, &priceFlightAero, &priceFlightLatam);
			    if(validation==1)
			    {
			    	calculateDescount(priceFlightAero, &priceDebitAero, 10);
			    	calculateDescount(priceFlightLatam, &priceDebitLatam, 10);
			    	calculateInterest(priceFlightAero, &priceCreditAero, 25);
			    	calculateInterest(priceFlightLatam, &priceCreditLatam, 25);
			    	calculatePriceBTC(priceFlightAero, &priceBTCAero);
			    	calculatePriceBTC(priceFlightLatam, &priceBTCLatam);
			    	priceKilometroAero = priceFlightAero/enterKilometro;
			    	priceKilometroLatam = priceFlightLatam/enterKilometro;
			    	diferencePrices(priceFlightAero,priceFlightLatam, &diferencePrice);
			    	printf("Calculo exitoso.\n");
			    	flag++;// bandera para saber si se calculo correctamente los datos.
			    	system("pause");
			    }
				break;
			case 4:
				if(flag!=0)//bandera si esta diferente a 0 es por que el calculo se hizo o hicieron correctamente.
				{
					showResult(enterKilometro, priceFlightAero, priceFlightLatam, priceDebitAero, priceDebitLatam, priceCreditAero, priceCreditLatam, priceBTCAero, priceBTCLatam, priceKilometroAero, priceKilometroLatam, diferencePrice);
				}
				else
				{
					printf("Por favor antes calcule los datos para informarlos.\n");
				}
			    system("pause");
				break;
			case 5:
			    showChargeForce();
				break;
			default:
			break;
		}
	}
	while(optionMenu!=6);
	return 0;
}

