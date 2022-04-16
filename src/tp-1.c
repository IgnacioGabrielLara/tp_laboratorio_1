/*
 ============================================================================
 Name        : tp-1.c
 Author      : Nacho
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main(void) {
	setbuf(stdout,NULL);
	   int opcion;
	    float kms = 0;
	    float precioAerolineas = 0;
	    float precioLatam = 0;
	    char salir = 'n';


	    do{
	    printf("1). Ingresar Kilometros: %.2f\n\n", kms);
		printf("2). Ingresar precio de vuelo: Aerolineas: %.2f Latam: %.2f\n\n",precioAerolineas ,precioLatam);
		printf("3). Calcular todos los costos:\n");
	        printf("a)Tarjeta de debito (Descuento 10)  \n");
	        printf("b)Tarjeta de credito (Interes 25) \n");
	        printf("c)Bitcoin( 1BTC -> 4606954.55 Pesos Argentinos\n");
	        printf("d)Mostrar precio por km (precio unitario)\n");
	        printf("e)Mostrar diferencia de precio ingresada(Latam-Aerolineas)\n\n");

		printf(	"4). Informar resultados:\n\n");
		printf(	"5). Carga forzada de datos.\n\n");
		printf("6). Salir.\n");

	    scanf("%d", &opcion);

	    while(opcion < 1 || opcion > 6)
	    {
	        printf("Error.Ingrese una opcion: \n");
	        scanf("%d", &opcion);

	    }

		switch (opcion)
		{
	    case 1:
	        system("cls");
	        printf("ingrese kms: ");
	        scanf("%f", &kms);
	        while(kms<0)
	        {
	            printf("Error.Ingrese kms: ");
	            scanf("%f", &kms);
	        }
	        system("cls");
	        break;

	    case 2:
	        system("cls");

	        printf("Ingrese precio de Aerolineas: ");
	        scanf ("%f", &precioAerolineas);

	        printf("Ingrese precio de Latam: ");
	        scanf("%f", &precioLatam);

	        system("cls");
	        break;

	    case 3:
	        if(precioAerolineas <= 0 || precioLatam <= 0)
	        {
	          printf("Error. No hay precios de vuelos ingresado.\n");
	          system("pause");
	        }
	        else
	        {
	            opcion3(precioAerolineas, precioLatam,0, kms);
	        }
	        system("cls");
	        break;

		case 4:
		    system("cls");
	        opcion3(precioAerolineas,precioLatam,1,kms);
	        system("pause");
	        system("cls");
	        break;

	    case 5:
	        opcion3(162965,159339,1,7090);
	        system("pause");
	        system("cls");
	        break;

	    case 6:
	        salir = 's';
		}
	    }while(salir != 's');


	return EXIT_SUCCESS;
}

