/*
 ============================================================================
 Name        : Trabajo_Practico_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajeros.h"
#define LEN 2000


int main() {
	setbuf(stdout,NULL);
    Passenger pasajero[LEN] ={
    {0,"Maria", "Lopez", 152.21, "25YT36TE",1,1,0},
    {0, "Jose","Ramirez", 145.36,"89RW13RR",2,3,0},
    {0,"Juan", "Ortiz", 199.32,"45SD89VC",2,1,0},
    {0,"Vanesa","Lloris", 101.15, "54DF21RE",3,1,0},
    {0,"Ivan","Liquin",652.21,"24RE32GD",1,2,0},
    {0,"Emiliano","Lamas", 235.32,"54GE65MN",2,1,0},
    {0,"Magui", "Ramos", 321.21,"54FE98AS",3,2,0},
    {0,"Soledad", "Romero",185.25,"65AS98FS",1,3,0},
    {0,"Veronica", "Miranda", 98.32,"78SF45ER",2,1,0}};

    int salir = 0;
    int idRemove;
    initPassenger(pasajero,LEN);

    do{

        switch(menu())
        {
        case 1:
            loadPassenger(pasajero,LEN);
            break;
        case 2:
         modifyPassenger(pasajero,LEN);
            break;
        case 3:
            printf("Ingrese ID: ");
            scanf("%d",&idRemove);
            removePassenger(pasajero,LEN,idRemove);
            break;
        case 4:
            reports(pasajero,LEN);
            break;
        case 5:
            salir = 5;

        }
    }while(salir != 5);


	return 0;
}

