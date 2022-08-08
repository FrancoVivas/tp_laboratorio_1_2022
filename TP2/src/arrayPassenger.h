#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define SALIR 0
#define MINOPCION 0
#define TAM 51
#define QTYPASS 5
#define CARGADO 1
#define MENOR 1
#define ADULTO 2
#define JUBILADO 3
#define DEMORADO 1
#define CANCELADO 2
#define ATERRIZADO 3
#define ACTIVO 4
#define VACIO 0
#define NAME 1
#define LASTNAME 2
#define PRICE 3
#define TYPEPASS 4
#define FLYCODE 5
#define DIA 6
#define MES 7
#define ANIO 8
#define ATOZ 1
#define ZTOA 0

typedef struct {
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct {
	int id;
	char name[51];
	char lastName [51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	eFecha fecha;
	int isEmpty;
}Passenger;

int findPassengerById(Passenger list[], int len, int id);
void cargaForzada (Passenger list[], int tam);
int GetDataToModify();
int ModifyPassenger (Passenger list[], int len, int tam);
int GetOccupiedId(Passenger list[], int len);
void InformSubMenu(Passenger list[], int len, int tam, int* mainMenuOption);
int AveragePrices(Passenger list[], int len);
int getPassenger(Passenger lista[], int tam, int* cantidadPass);
int getTypePassenger();
int getStatusFlight();
void EmptySpaces (Passenger lista[], int tam, int* flagEmptyList);
int initPassengers(Passenger list[], int len);
int addPassenger(Passenger list[], int len, int statusFlight,int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int dia, int mes, int anio);
int findPassengerById(Passenger list[], int len,int id);
int removePassenger(Passenger list[], int len, int id);
int sortPassengers(Passenger list[], int len, int order);
int printPassengers(Passenger list[], int length);
int printOnePassenger(Passenger list);
int sortPassengersByCode(Passenger list[], int len, int order);
int GetOrder(char order[], int len);
void SortZtoA(Passenger list[], int len);
void SortAtoZ(Passenger list[], int len);
void printPassengerActive (Passenger list[], int len);
void TopPartChart();
void BottomPartChart();
#endif /* ARRAYPASSENGER_H_ */
