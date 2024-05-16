#include <stdio.h>
#include <math.h>

// Declaración de funciones
int minimo(int arreglo[], int tamano);

int main(){
    int numeros[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    int min = minimo(numeros, tamano);
    printf("El número mínimo del arreglo es: %d \n", min);

    return 0;
}

////****FUNCIONES****////

/*
 * Esta función busca el número menor de un arreglo.
 * @param arreglo[]: El arreglo a manipular.
 * @param tamano:    El tamaño del arreglo.
 * @return min_num:  El número mínimo del arreglo.
*/
int minimo(int arreglo[], int tamano){
    int min_num = arreglo[0];

    /* Se recorre todo el arreglo comparando con el número
    almacenado y si este es menor se cambia */
    for (int i = 1; i < tamano; i++){
        if (arreglo[i] < min_num){
            min_num = arreglo[i];
        }
    }
    return min_num;
}