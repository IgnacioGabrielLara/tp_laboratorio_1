/*
 * pasajeros.c
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajeros.h"
static int id = 1000;
static int idIncremental();
static int idIncremental()
{

    return id++;
}
int menu()
{
    int opcion;
    system("cls");
    printf("********** ABM PASAJEROS ***********\n");
    printf("1. Alta pasajeros\n");
    printf("2. Modificar pasajeros\n");
    printf("3. Baja pasajero\n");
    printf("4. Informar\n");
    printf("5. Salir\n");

    scanf("%d", &opcion);


    return opcion;
}

int initPassenger(Passenger list[], int len)
{

    if( list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }

    }

    return 0;
}

int searchFree(Passenger list[], int len)
{
    int free;
     if( list != NULL && len > 0 )
    {
        free = -1;

        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 1)
            {
                free = i;
                break;
            }
        }
    }

    return free;
}

int loadPassenger(Passenger list[], int len)
{
    Passenger aux;
    int confirm;

     aux.id = idIncremental();

    system("cls");
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(aux.name);


    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(aux.lastname);

    system("cls");
    printf("Ingrese precio: ");
    scanf("%f", &aux.price);

    system("cls");
    printf("Ingrese tipo de pasajero:\n 1. Primera clase \n 2. Ejecutivo \n 3. Turista\n");
    fflush(stdin);
    scanf("%d", &aux.typePassenger);

    system("cls");
    printf("Ingrese codigo de vuelo: ");
    fflush(stdin);
    gets(aux.flycode);

    system("cls");
    printf("Estados de vuelo: \n1.Activo\n2.Suspendido\n3.Demorado");
    scanf("%d", &aux.statusFlight);

    system("cls");
    printf("Confirmar cagar:\n 1.SI \n 2.NO\n");
    scanf("%d", &confirm);

    if(confirm == 1)
    {
      // addPassenger(list, len, aux.id,  aux.name,  aux.lastname,  aux.price, aux.typePassenger, aux.flycode, aux.statusFlight);
     int i = searchFree(list,len);
     list[i] = aux;

    }

    return 0;
}

int addPassenger(Passenger list[], int len, int id, char name[], char lastname[], float price, int typePassenger, char flycode[], int statusflight)
{
    Passenger aux;
    int i;
    int ok = 00;
    if(list != NULL && len > 0)
    {
        i = searchFree(list,len);
        if(i<0 || i>2000)
        {
            printf("No hya lugar en el sisema");
        }
        else
        {
            aux.id = id;
            aux.name[51] = *name;
            aux.lastname[51] = *lastname;
            aux.price = price;
            aux.typePassenger = typePassenger;
            aux.flycode[10] = *flycode;
            aux.statusFlight = statusflight;
            aux.isEmpty = 0;

            list[i] = aux;
            ok = 1;
        }

    }

    return ok;
}

void showPassenger(Passenger list)
{
    printf("%d\t    %10s   %10s\t  %2.2f\t  %2d\t  %8s\t  %2d\n",
    list.id,
    list.name,
    list.lastname,
    list.price,
    list.typePassenger,
    list.flycode,
    list.statusFlight
    );

}
int printPassenger(Passenger list[], int len)
{
    int todoOk = 0;
    int flag = 1;
    if( list != NULL && len > 0)
    {
        system("cls");
        printf("       *** Listado de Pasajeros ***\n");
        printf("   id       nombre               apellido               precio              tipo               codigo estado\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 0)
            {
                showPassenger(list[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay pasajeros en el sistema\n");
        }
        system("pause");
        todoOk = 1;
    }
    return todoOk;
}

int findPassengerById(Passenger list[], int len, int id)
{

    int indice;
    if( list != NULL && len > 0 )
    {
       indice = -1;
        for(int i=0; i < len; i++)
        {
            if( !list[i].isEmpty  && list[i].id == id)
            {
                indice = i;
                break;
            }
        }

    }
    return indice;
}

int removePassenger(Passenger list[], int len, int id)
{
    int todoOk = 0;
    int indice;

    char confirma;
    if( list != NULL && len > 0 )
    {
        indice = findPassengerById(list,len,id);

        if( findPassengerById(list, len, id))
        {
              showPassenger(list[indice]);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    list[indice].isEmpty = 1;
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("Baja cancelada\n");
                }

            }

            todoOk = 1;
        }


    return todoOk;
}

int sortPassenger(Passenger list[], int len,  int order)
{
    int todoOk = 0;
    Passenger auxPass;

    if( list != NULL && len > 0)
    {
        for(int i=0; i < len - 1; i++)
        {
            for(int j= i+1; j < len; j++)
            {
                if( list[i].typePassenger > list[j].typePassenger && strcmp(list[i].lastname, list[j].lastname) > order )
                {
                    auxPass = list[i];
                    list[i] = list[j];
                    list[j] = auxPass;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int reports(Passenger list[], int len)
{
    int opcion;

    printf("*********** INFORMES **********\n\n");
    printf("1. Listado de pasajeros ordenados alfabeticamente por apelido y tipo de pasajero\n");
    printf("2. Total y promedio de los precios de pasajes, y cuantos pasajeros superan el precio promedio\n");
    printf("3. Listado de pasajeros por codigo de vuelo y estados ACTIVOS\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        sortPassenger(list,len,1);
        break;
    case 2:
        informe2(list,len);
        break;
    case 3:
        informe3(list,len);
        break;
    }
    system("pause");
    return 0;
}
int informe2(Passenger list[],int len)
{
    float total = 0;
    float promedio;
    int superan = 0;
    if(list != NULL && len>0)
    {
        for(int i=0;i>len;i++)
        {
            total= total + list[i].price;

        }
        promedio =  total/(float)len;

        for(int i=0;i>len;i++)
        {
            if(list[i].price > promedio)
            {
                superan++;
            }

        }

        printf("El total de los precios de los pasajes es: %.2f\n",total);
        printf("El promedio del total es: %.2f\n", promedio);
        printf("La cantidad de pasajeros que superan el promedio es: %d", superan);


    }

    return 0;
}
int informe3(Passenger list[], int len)
{
    int ok = 0;
    Passenger auxPass;

    if( list != NULL && len > 0)
    {
        for(int i=0; i < len - 1; i++)
        {
            for(int j= i+1; j < len; j++)
            {
                if( list[i].statusFlight == 1 && strcmp(list[i].flycode, list[j].flycode) > 1 )
                {
                    auxPass = list[i];
                    list[i] = list[j];
                    list[j] = auxPass;
                }
            }
        }
        ok = 1;
    }
    return ok;
}
int menuModifyPassenger()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Tipo de pasajero\n");
    printf("5. Codigo de vuelo\n");
    printf("6. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int modifyPassenger(Passenger list[], int len)
{
    int todoOk = 0;
    int indice=-1;
    int id;
    char auxName[51];
    char auxLastname[51];
    float auxprice;
    int auxTypePassenger;
    char auxFlycode [10];


    if( list != NULL && len > 0 )
    {
       system("cls");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findPassengerById(list, len, id);


            if(indice == -1)
            {
                printf("No existe un empleado con id: %d en el sistema\n", id);
            }
            else
            {


                switch(menuModifyPassenger())
                {

                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxName);
                    strcpy(list[indice].name, auxName);
                    printf("Nombre modificado!");
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxLastname);
                    strcpy(list[indice].lastname, auxLastname);
                    printf("Apellido modificado!");
                    break;
                case 3:
                    printf("Ingrese nuevo precio: ");
                    scanf("%f", &auxprice);
                    list[indice].price = auxprice;
                    printf("Precio modficado!");
                    break;
                case 4:
                    printf("Ingrese nuevo tipo de pasajero: ");
                    scanf("%d", &auxTypePassenger);
                    list[indice].typePassenger = auxTypePassenger;
                    printf("Sueldo modificado!");
                    break;
                case 5:
                    printf("Ingrese nuevo codigo: ");
                    fflush(stdin);
                    gets(auxFlycode);
                    strcpy(list[indice].flycode, auxFlycode);
                    printf("Codigo modificado!");
                    break;

                }

                system("pause");

            }

            todoOk = 1;
        }

    return todoOk;
}




