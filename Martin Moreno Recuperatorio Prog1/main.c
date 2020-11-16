#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    1.  Crear una función llamada aplicarDescuento que reciba como parámetro el
    precio de un producto y devuelva el valor del producto con un descuento del 5%.
    Realizar la llamada desde el main. *
*/

/*
    2.  Crear una función que se llame contarCaracteres que reciba una cadena de
    caracteres como primer parámetro y un carácter como segundo y devuelva la
    cantidad de veces que ese carácter aparece en la cadena *

*/

/*
    3. Dada la estructura Notebook(id, procesador, marca, precio) generar una
    función que permita ordenar un array de dicha estructura por marca. Ante
    igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
*/



typedef struct
{
    int id;
    char procesador[20];
    char marca [20];
    float precio;
}Notebook;

float aplicarDescuento(float precio); // ejercicio 1

int contarCaracteres(char cadena[],char c); //ejercicio 2

void ordenarProductoPorMarca(Notebook pc[],int tam); //ejercicio 3


int main()
{
    float precio1=30;
    int cantidadDeCaracteres=0;
    char cadena1[10];
    strcpy(cadena1,"anna");

    precio1=aplicarDescuento(precio1);
    cantidadDeCaracteres= contarCaracteres(cadena1,'a');
    printf("%f",precio1);
    printf("cantidad de veces que aparece a es %d",cantidadDeCaracteres);

    return 0;
}


float aplicarDescuento(float precio) // ejercicio 1
{

    precio-=((precio/100.0)*5.0);
    return precio;
}

int contarCaracteres(char cadena[],char c) //ejercicio 2
{
    int cant=0;

    int tam=strlen(cadena);

    for(int i=0; i<tam; i++)
    {
        if(cadena[i]==c)
        {
            cant++;
        }
    }

    return cant;
}

void ordenarProductoPorMarca(Notebook pc[],int tam) //ejercicio 3
{
    Notebook auxPc;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(pc[j].marca,pc[i].marca)<0)
            {
                auxPc=pc[i];
                pc[i]=pc[j];
                pc[j]=auxPc;
            }
            else if(strcmp(pc[j].marca,pc[i].marca)==0)
            {
                if(pc[i].precio < pc[j].precio)
                {
                    auxPc=pc[i];
                    pc[i]=pc[j];
                    pc[j]=auxPc;
                }
            }
        }
    }
}
