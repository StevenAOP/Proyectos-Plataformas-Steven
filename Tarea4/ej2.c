#include <stdio.h>
#include <math.h>

// Declaración de funciones
int minimo(int arreglo[], int tamano);
int maximo(int arreglo[], int tamano);
void encontrarMinMax(int *arreglo, int * minimo, int * maximo, int longitud);


int main(){
    int numeros[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    int min = minimo(numeros, tamano);
    printf("El número mínimo del arreglo es: %d \n", min);

    int max = maximo(numeros, tamano);
    printf("El número máximo del arreglo es: %d \n \n", max);

    // Definiendo los punteros para la función encontrarMinMax()
    int min2;
    int max2;
    int * ptr_numeros = numeros;
    int * ptr_minimo = &min2;
    int * ptr_maximo = &max2;

    printf("Usando punteros\n");
    encontrarMinMax(ptr_numeros, ptr_minimo, ptr_maximo, tamano);
    printf("El número mínimo y máximo del arreglo son %d y %d respectivamente.\n", min2, max2);

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

/*
 * Esta función busca el número mayor de un arreglo.
 * @param arreglo[]: El arreglo a manipular.
 * @param tamano:    El tamaño del arreglo.
 * @return max_num:  El número mínimo del arreglo.
*/
int maximo(int arreglo[], int tamano){
    int max_num = arreglo[0];

    /* Se recorre todo el arreglo comparando con el número
    almacenado y si este es mayor se cambia */
    for (int i = 1; i < tamano; i++){
        if (arreglo[i] > max_num){
            max_num = arreglo[i];
        }
    }
    return max_num;
}


/*
 * Esta función almacena en dos punteros los numeros menores 
   y menores de un arreglo dado en otro puntero
 * @param *arreglo: El puntero de un arreglo a manipular.
 * @param *minimo:  El puntero donde se almacena el número mínimo del arreglo.
 * @param *maximo:  El puntero donde se almacena el número máximo del arreglo.
 * @param longitud: El tamaño del arreglo.
*/
void encontrarMinMax(int *arreglo, int * minimo, int * maximo, int longitud){

    // Dando los primeros datos del arreglo a minimo y maximo
    *minimo = *arreglo;
    *maximo = *arreglo;

    /* Se recorre todo el arreglo del puntero comparando con el número
    almacenado y si este es menor se cambia */
    for (int i = 1; i < longitud; i++){
        if (*(arreglo + i) < *minimo){
            *minimo = *(arreglo + i);
        }
    }

    /* Se recorre todo el arreglo del puntero comparando con el número
    almacenado y si este es mayor se cambia */
    for (int i = 1; i < longitud; i++){
        if (*(arreglo + i) > *maximo){
            *maximo = *(arreglo + i);
        }
    }
}