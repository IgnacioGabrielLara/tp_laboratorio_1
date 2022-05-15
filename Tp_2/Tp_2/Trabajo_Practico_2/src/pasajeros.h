	/*
 * pasajeros.h
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastname[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}typedef Passenger;

#endif // PASAJEROS_H_INCLUDED

int menu();

int initPassenger(Passenger list[], int len);

int searchFree(Passenger list[], int len);

int loadPassenger(Passenger list[], int len);

int addPassenger(Passenger list[], int len, int id, char name[], char lastname[], float price, int typePassenger, char flycode[], int statusflight);

void showPassenger(Passenger list);

int printPassenger(Passenger list[], int len);
int findPassengerById(Passenger list[], int len, int id);
int removePassenger(Passenger list[], int len, int id);

int sortPassenger(Passenger list[], int len,  int order);
int menuModifyPassenger();
int modifyPassenger(Passenger list[], int len);
int reports(Passenger list[], int len);
int informe2(Passenger list[],int len);
int informe3(Passenger list[], int len);

