#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(int opcionElegida)
{
    //Muestra todas las opciones del menu
    printf("\nPara ingresar el primer operando, ingrese 1. ");
    printf("\nPara ingresar el segundo operando, ingrese 2. ");
    printf("\nPara calcular las operaciones, ingrese 3. ");
    printf("\nPara mostrar los resultados, ingrese 4. ");
    printf("\nPara salir, ingrese 5. ");
    printf("\n\nIngrese numero: ");
    scanf("\n %d",&opcionElegida);
    system("cls");

    //Retorna la opcion elegida
    return opcionElegida;
}

float pedirNumero(float operando, int opcionElegida)
{
    //Si el usuario ingreso 1 en el menu
    if(opcionElegida==1)
    {
        //Toma primer valor
        printf("\nIngrese el primer operando. A=");
        scanf("%f",&operando);
        system("cls");
    }
    else
    {
        //Si el usuario ingreso 2 en el menu
        if(opcionElegida==2)
        {
            //Toma segundo valor
            printf("\nIngrese el segundo operando. B=");
            scanf("%f",&operando);
            system("cls");
        }
    }

    //Retorna el valor ingresado
    return operando;
}

float sumarOperandos(float primerOperando, float segundoOperando)
{
    //Variable que guarda el resultado de la suma
    float suma;

    suma=primerOperando+segundoOperando;

    //Resultado
    return suma;
}

float restarOperandos(float primerOperando, float segundoOperando)
{
    //Variable que guarda el resultado de la resta
    float resta;

    resta=primerOperando-segundoOperando;

    //Resultado
    return resta;
}

float dividirOperadores(float primerOperando, float segundoOperando)
{
    //Variable que guarda el resultado de la division
    float division;

    //--------Validacion de la division--------
    //Si el segundo operando es 0, el resultado es infinito
    if(!segundoOperando)
    {
        division=0;
    }
    //Si el segundo operando no es 0
    else
    {
        //Se realiza la division
        division=primerOperando/segundoOperando;
    }

    //Resultado
    return division;
}
float multiplicarOperadores(float primerOperando, float segundoOperando)
{
    //Variable que guarda el resultado de la multiplicacion
    float multiplicacion;

    multiplicacion=primerOperando*segundoOperando;

    //Resultado
    return multiplicacion;
}

int verificarDecimal(float operando)
{
    int operandoEntero;
    int verificacionFactorial=1;

    //Asigno la parte entera del posible decimal a una variable
    operandoEntero=operando;

    //Si la diferencia entre esas dos variables es mayor que 0
    //verifica que el valor ingresado es un decimal
    if(operando-operandoEntero>0)
    {
        verificacionFactorial=0;
    }

    //Retorna 0 si no es posible realizar el factoreo y 1 si es posible
    return verificacionFactorial;
}

int factorizarOperando(float operando)
{
    int factorizacionOperando=1;
    int verificacionFactorial;

    //En esta variable se guarda 1 si es 0
    verificacionFactorial= verificarDecimal(operando);

    //--------Validacion factorizacion-------
    //Si es un numero negativo o decimal, el resutado va a ser 0
    //y posteriormente se va a mostrar que el resultado no se pudo calcular
    if(operando<0 || verificacionFactorial==0)
    {
        factorizacionOperando=0;
    }
    else
    {
        //Si el valor ingresado es 0 el resultado es 1
        if(operando==0)
        {
            factorizacionOperando=1;
        }
        //Si es posible realizar el factoreo
        else
        {
            //Calcula el factoreo del numero ingresado si no se cumplen las condiciones anteriores
            for(int i = 1;i<=operando;i++)
            {
                factorizacionOperando *= i;
            }
        }

    }
    //Retorna el resultado del factoreo
    return factorizacionOperando;
}

void mostrarOperaciones(float primerOperando, float segundoOperando, float sumaResuelta, float restaResuelta, float divisionResuelta, float multiplicacionResuelta, int factorizacionPrimerOperandoResuelta, int factorizacionSegundoOperandoResuelta)
{
    printf("Teniendo en cuenta que A=%.2f y que B=%.2f\n\n",primerOperando,segundoOperando);

    //Resultado de la suma
    printf("El resultado de A+B es: %.2f \n",sumaResuelta);

    //Resultado de la resta
    printf("El resultado de A-B es: %.2f \n",restaResuelta);

    //----------------Posibles resultados de la division-------------
    //Cuando el divisor es 0
    if(!divisionResuelta)
    {
        printf("El resultado de A/B es: Infinito\n");
    }
    else
    {
        //Cuando el divisor es distinto de 0
        printf("El resultado de A/B es: %.2f \n",divisionResuelta);
    }

    //Resultado de la multiplicacion
    printf("El resultado de A*B es: %.2f \n",multiplicacionResuelta);

    //-----------------Posibles resultados del factoreo-----------------------
    //Cuando no es posible calcular el factorial de los DOS valores ingresados
    if(!factorizacionPrimerOperandoResuelta && !factorizacionSegundoOperandoResuelta)
    {
        printf("El factorial de A no es posible de calcular y El factorial de B tampoco\n");
    }
    else
    {
        //Cuando A no es posible de calcular pero B si
        if(factorizacionSegundoOperandoResuelta!=0 && !factorizacionPrimerOperandoResuelta)
        {
            printf("El factorial de A no es posible de calcular y El factorial de B es: %d \n\n",factorizacionSegundoOperandoResuelta);
        }
        else
        {
            //Cuando A es posible de calcular pero B no
            if(factorizacionPrimerOperandoResuelta!=0 && !factorizacionSegundoOperandoResuelta)
            {
                printf("El factorial de A es: %d y El factorial de B no es posible de calcular. \n\n",factorizacionPrimerOperandoResuelta);
            }
            else
            {
                //Cuando es posible calcular el factorial de los dos valores ingresados
                printf("El factorial de A es: %d y El factorial de B es: %d \n\n",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
            }
        }
    }
}
