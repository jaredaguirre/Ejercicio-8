#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define esLetra(x) ((x >= 'A' && x <= 'Z') || (x >= 'a' && x<= 'z'))?1:0

/*
Lee la primer palabra de una cadena, indica cuantas veces aparece.
Indica la longitud de la palabra mas larga
Indica cuantas palabras hay en total
*/
void primerPalabra(char* p)
{
    char palabra[25];
    char temp[25];
    int ocurrencias = 0, lon = 0, cantPal = 1, pmaslarga = 0;
    sscanf(p, "%s", palabra);

    /*Lectura de caracter por caracter*/
    while(*p)
    {
        if(esLetra(*p))
            lon++;
        else
        {
            if(lon > pmaslarga)
                pmaslarga = lon;
            if(*p == ' ')
            {
                /*Cada vez que aparezca un espacio, se comparará la primer palabra con la siguiente a dicho espacio*/
                sscanf(p+1, "%s", temp);
                if(!strcmp(palabra, temp))
                    ocurrencias++;
                cantPal++;
            }
            lon = 0;

        }
        p++;
    }
    /*Resultados*/
    printf("La palabra \"%s\" aparece %d veces\n", palabra, ocurrencias+1);
    printf("Longitud de la palabra mas larga: %d\n", pmaslarga);
    printf("Cantidad de palabras: %d\n", cantPal);

}
