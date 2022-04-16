/*
 * funcion.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

void opcion3(float aerolinea, float latam, int opcion4, float kms)
{


    float btc = 4610472.64;
    float totalAerolineas;
    float totalLatam;
    float diferencia;

    totalAerolineas = aerolinea * kms;
    totalLatam = latam * kms;


        system("cls");


            //PRECIO AEROLINEAS
            float debitoAerolineas = totalAerolineas - ( totalAerolineas*10) / 100;

            float creditoAerolineas = totalAerolineas + (totalAerolineas*25)/100;

            float bitcoinAerolineas = totalAerolineas/btc;


            //PRECIO LATAM
            float debitoLatam = totalLatam - ( totalLatam*10) / 100;

            float creditoLatam = totalLatam + (totalLatam*25)/100;

            float bitcoinLatam = totalLatam/btc;

            if(opcion4 == 1)
            {
                printf("KMs Ingresados: %.2f\n\n", kms);

                printf("Precio Latam: %.2f\n", totalLatam);
                printf("a).Precio con tarjeta de débito: %.2f\n", debitoLatam);
                printf("b).Precio con tarejta de crédito: %.2f\n", creditoLatam);
                printf("c).Precio pagando con Bitcoin: %f\n", bitcoinLatam);
                printf("d).Precio unitario: %.2f\n\n", latam);

                printf("Precio Aerolineas: %.2f\n", totalAerolineas);
                printf("a).Precio con tarjeta de débito: %.2f\n", debitoAerolineas);
                printf("b).Precio con tarejta de crédito: %.2f\n",creditoAerolineas);
                printf("c).Precio pagando con Bitcoin: %f\n",bitcoinAerolineas);
                printf("d).Precio unitario: %.2f\n\n",aerolinea);

                if(totalAerolineas>totalLatam)
                {
                    diferencia = totalAerolineas - totalLatam;
                }
                else
                {
                    diferencia = totalLatam - totalAerolineas;
                }

                printf("La diferencia de precio es: %.2f\n", diferencia);

            }

}

