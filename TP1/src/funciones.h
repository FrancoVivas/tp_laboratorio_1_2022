/** \brief          Despliega el menu y le pide al usuario que ingrese un numero para realizar realizar una accion
 *
 * \param int       Variable que guarda la respuesta del usuario
 * \return int      Opcion elegida
 *
 */
int mostrarMenu(int);


/** \brief          Pide al usuario que ingrese el operando
 *
 * \param float     Variable que guarda el valor ingresado
 * \param int       Respuesta del menu
 * \return float    Valor ingresado
 *
 */
float pedirNumero(float,int);


/** \brief          Suma los valores ingresados por el usuario
 *
 * \param float     Primer valor
 * \param float     Segundo valor
 * \return float    El resultado de la suma entre los dos valores
 *
 */
float sumarOperandos(float,float);


/** \brief          Resta los valores ingresados por el usuario
 *
 * \param float     Primer valor
 * \param float     Segundo valor
 * \return float    El resultado de la resta entre los valores
 *
 */
float restarOperandos(float,float);


/** \brief          Divide los valores ingresados por el usuario
 *
 * \param float     Primer valor
 * \param float     Segundo valor
 * \return float    El resultado de la division entre los valores
 *
 */
float dividirOperadores(float,float);


/** \brief          Multiplica los valores ingresados por el usuario
 *
 * \param float     Primer valor
 * \param float     Segundo valor
 * \return float    El resultado de la multiplicacion entre los valores
 *
 */
float multiplicarOperadores(float,float);


/** \brief          Verifica si el valor ingresado es entero o decimal
 *
 * \param float     Valor ingresado
 * \return int      Si es decimal (0) si es entero (1)
 *
 */
int verificarDecimal(float);


/** \brief          Factorea el valor ingresado por el usuario
 *
 *
 * \param float     Valor
 * \return int      Resultado de la factorizacion del valor
 *
 */
int factorizarOperando(float);


/** \brief          Realiza todos los calculos con los valores ingresados
 *
 * \return void     No retorna nada
 *
 */
void calcularOperaciones();


/** \brief          Muestra todas las operanciones realizadas
 *
 * \param float     Primer valor
 * \param float     Segundo valor
 * \param float     Resultado de la suma
 * \param float     Resultado de la resta
 * \param float     Resultado de la division
 * \param float     Resultado de la multiplicacion
 * \param int       Resultado de la factorizacion
 * \param int       Resultado de la factorizacion
 * \return void     No Retorna nada
 *
 */
void mostrarOperaciones(float,float,float,float,float,float,int,int);
