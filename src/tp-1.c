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
	    	//Al entrar el do/while se imprime el menu, una vez se van ingresando los valores estos se reemplazan
	    	//y al volver a ingresar quedan impresos
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

		//Aqui se ingresa la opcion y luego se valida
	    int scan = scanf("%d", &opcion);

	    while(opcion < 1 || opcion > 6 || !scan)
	    {
	    	fflush(stdin);
	        printf("Error.Ingrese una opcion: \n");
	        scan = scanf("%d", &opcion);

	    }

	    //Una vez validada la opcion entra aqui para que se desarrolle segun lo ingresado
		switch (opcion)
		{
	    case 1:
	    	//Pide, valida y guarda los Km
	        system("cls");
	        printf("ingrese kms: ");
	        int scan2 = scanf("%f", &kms);
	       kms = validar(kms,scan2);
	        system("cls");
	        break;

	    case 2:
	    	//Pide, valida y guarda los precios
	        system("cls");

	        printf("Ingrese precio de Aerolineas: ");
	        int scan3 = scanf ("%f", &precioAerolineas);
	        precioAerolineas = validar(precioAerolineas, scan3);

	        printf("Ingrese precio de Latam: ");
	        int scan4 = scanf("%f", &precioLatam);
	        precioLatam = validar(precioLatam, scan4);
	        system("cls");
	        break;

	    case 3:
	    	//Valida si hay precios ingresado, si lo hay ejecuta la funcion donde se calculan los pagos

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
		    //Imprime los resultados
			system("cls");
	        opcion3(precioAerolineas,precioLatam,1,kms);
	        system("pause");
	        system("cls");
	        break;

	    case 5:
	    	//Carga forzada de datos
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

