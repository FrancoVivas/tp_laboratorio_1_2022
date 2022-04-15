#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int calculateInterest(float num, float *result, float porcent);
///Funcion para calcular el total con interes de un numero .
/// @param num (Numero a calcular con intereses)
/// @param result (Resultado que se guarda ya calculado el numero con el interes.)
/// @param porcent (El porcentaje de interes que desee.)
/// @return retorna 0 si todo salio bien

int calculateDescount(float num, float *result, float porcent);
/// Funcion para calcular el total con descuento de un numero.
/// @param num (Numero a calcular con descuento)
/// @param result (Resultado que se guarda ya calculado el numero con el descuento.)
/// @param porcent (El porcentaje de descuento que desee.)
/// @return retorna 0 si todo salio bien

int calculatePriceBTC(float num, float *result);
/// Funcion para calcular el precio en BTC(BITCOIN).
/// @param num (numero a calcular en BITCOIN)
/// @param result(resultado del numero en BITCOIN)
/// @return retorna 0 si todo el calculo salio bien

int diferencePrices(float num1, float num2, float *result);
///Funcion para calcular la diferencia de 2 numeros (siempre queda positivo)
/// @param num1 (Primer numero a calcular diferencia)
/// @param num2 (Segundo numero a calcular diferencia)
/// @param result(Resultado de la diferencia de los numeros en positivo)
/// @return retorna 0 si todo el calculo salio bien

int getKilometro(float* pResult, char* message, char* messageError, float minimum, int retry);
/// Funcion para obtener los kilometros correctamente validando que sea mayor a 0
/// @param pResult(Resultado correcto de los Kilometros validado)
/// @param message(Mensaje para que el usuario ingrese el dato)
/// @param messageError(Mensaje de error si es menor a 0)
/// @param minimum(El resultado minimo a obtener que en este caso seria 0)
/// @param retry ( Numero entero de intentos para que el usuario vuelva a ingresar el dato si es que fallo)
/// @return retorna 0 si el calculo se hizo correctamente

int getPriceAeroLatam(float *pResultAero, float *pResultLatam, char* messageAero,char *messageLatam, char* messageError, int tryAero, int tryLatam);
/// Funcion para obtener los precios de vuelo Aerolineas y Latam sean mayor igual a 0.
/// @param pResultAero (Resultado de precio de vuelo Aerolineas validado)
/// @param pResultLatam(Resultado de precio de vuelo Latam validado)
/// @param messageAero( Mensaje para ingresar precio Aerolineas)
/// @param messageLatam(Mensaje para ingresar precio Latam)
/// @param messageError(Mensaje de error si no se ingreso correctamente el precio que sea mayor a 0)
/// @param tryAero(Numero de intentos para ingresar los datos de precio Aerolineas)
/// @param tryLatam(Numero de intentos para ingresar los datos de precio Latam)

int maskMenu(int *option,float kilometer, float priceAero, float priceLatam);
/// Funcion que mostrara el menu principal con las opciones de menu validadas.
/// @param option ( Opcion para el menu validado)
/// @param kilometer( Kilometros que se mostraran en el menu si se ingreso el dato)
/// @param priceAero( Precio de Aerolineas que se mostrara en el menu si se ingreso el dato)
/// @param priceLatam( Precio de Latam que se mostrara en el menu si se ingreso el dato)
/// @return retorna 0 si toda la funcion se ejecuto correctamente

int validationIngress(float *kilometer, float *priceAero, float *priceLatam);
/// Funcion para validar si se ingreso o no los datos de Kilometro precioAerolineas o preciosLatam
/// @param kilometer ( Valida si se ingreso los kilometro)
/// @param priceAero	(Valida si se ingreso el precio de Aerolineas)
/// @param priceLatam(Valida si se ingreso el precio de Latam )


void showResult(float kilometer, float priceAero, float priceLatam, float priceDebitAero, float priceDebitLatam, float priceCreditAero, float priceCreditLatam, float priceBTCAero, float priceBTCLatam, float priceKilometroAero, float priceKilometroLatam, float diferencePrice);
/// Funcion para mostrar los resultados
/// @param kilometer(Kilometros ingresados)
/// @param priceAero(Precio de vuelo Aerolineas ingresado)
/// @param priceLatam(Precio de vuelo Latam ingresado)
/// @param priceDebitAero(Precio en T.Debito Aerolineas ingresado)
/// @param priceDebitLatam(Precio en T.Debito Latam ingresado)
/// @param priceCreditAero(Precio en T.Credito Aerolineas ingresado)
/// @param priceCreditLatam(Precio en T.Credito Latam ingresado)
/// @param priceBTCAero(Precio en BTC Aerolineas )
/// @param priceBTCLatam(Precio en BTC Latam )
/// @param priceKilometroAero(Precio por kilometros de Aerolineas)
/// @param priceKilometroLatam(Precio por kilometros de Latam)
/// @param diferencePrice(Diferencia de precio de Aerolineas y Latam)
///
void showChargeForce();
/// Funcion para mostrar la carga forzada mencionada en la consigna del TP

#endif /* FUNCIONES_H_ */
