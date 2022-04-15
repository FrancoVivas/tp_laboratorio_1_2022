#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //Declaracion de variables

    //A = PRIMER OPERANDO
    //B = SEGUNDO OPERANDO
    float a;
    float b;
    int respuestaMenu;
    float sumaResuelta;
    float restaResuelta;
    float divisionResuelta;
    float multiplicacionResuelta;
    int factorizacionPrimerOperandoResuelta;
    int factorizacionSegundoOperandoResuelta;
    int flagUno;
    int flagDos;
    int flagTres;

    //Inicializacion de variables
    a=0;
    b=0;
    flagUno=0;
    flagDos=0;
    flagTres=0;

    do
    {
        //Muestro valores actuales del  PRIMER y SEGUNDO operando
        printf("\n  -----------------------");
        printf("\n|                        |");
        printf("\n|    A=%.2f   B=%.2f     |",a,b);
        printf("\n|                        |");
        printf("\n  -----------------------");

        //Muestra el menu y guarda la respuesta del usuario
        respuestaMenu = mostrarMenu(respuestaMenu);

        //Segun la respuesta del usuario, realiza una accion
        switch (respuestaMenu)
        {

            //Pido PRIMER operando
            case 1:

                a = pedirNumero(a, respuestaMenu);
                flagUno=1;

                break;

            //Pido SEGUNDO operando
            case 2:

                //Si NO ingreso el PRIMER operando
                if(!flagUno)
                {
                    printf("Tiene que ingresar el operando 1\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                b = pedirNumero(b, respuestaMenu);
                flagDos=1;
                }

                break;

            //Calculo las operaciones
            case 3:

                //Si NO ingreso uno o mas operandos
                if(!flagUno || !flagDos)
                {
                    printf("Para calcular primero tiene que ingresar los operandos\n");
                    system("pause");
                    system("cls");
                }
                //Si ingreso correctamente los operandos
                else
                {
                sumaResuelta=sumarOperandos(a,b);
                restaResuelta=restarOperandos(a,b);
                divisionResuelta=dividirOperadores(a,b);
                multiplicacionResuelta=multiplicarOperadores(a,b);
                factorizacionPrimerOperandoResuelta=factorizarOperando(a);
                factorizacionSegundoOperandoResuelta=factorizarOperando(b);
                flagTres=1;
                }

                break;

            //Muestro los resultados
            case 4:
                //Si NO calculo antes de mostrar
                if(!flagTres)
                {
                    printf("No se puede calcular antes de mostrar\n");
                    system("pause");
                    system("cls");
                }
                //Si calculo antes de mostrar
                else
                {
                    mostrarOperaciones(a,b,sumaResuelta,restaResuelta,divisionResuelta,multiplicacionResuelta,factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
                    printf("Si continua, los datos van a ser restablecidos a 0\n");
                    system("pause");
                    system("cls");
                    //Se resetan los valores para volver a usar la calculadora
                    flagUno=0;
                    flagDos=0;
                    flagTres=0;
                    a=0;
                    b=0;
                }

                break;

            //Salir de la calculadora
            case 5:

                //Mensaje de salida
                printf("Apagando...\n\n\n\n\n");
                break;

            //Si NO ingreso ninguna de las opciones del menu
            default:
                {
                    //Mensaje de ERROR
                    printf("ERROR. La opcion ingresada no coincide con las disponibles.\n\n");
                }
        }


    //Condicion que hace que el bucle itere
    }while(respuestaMenu != 5);
}
