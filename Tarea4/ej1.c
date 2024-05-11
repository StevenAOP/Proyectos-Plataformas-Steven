#include <stdio.h>

// Declaración de la funciones
int solicitud();
int busqueda_lineal(int x, int arreglo[]);

int main(){
    int num = solicitud();
    int numeros[] = {2, 4, 6, 23, 56, 79};
    busqueda_lineal(num, numeros);
    return 0;
}


// Funciones


/*
 * Esta función solicida un número al usuario
 * @return El número ingresado
*/
int solicitud() {
    int n;
    printf("Ingrese un número: ");
    scanf("%d", &n); // Leyendo
    return n;
}


/*
 * Esta función busca un número dentro de un arreglo dado.
 * @param x El número a buscar
 * @param arreglo[] El arreglo a manipular
 * @return Cero para salir
*/
int busqueda_lineal(int x, int arreglo[]){
    int len = 6;
    for (int i = 0; i < len; i++){
        if (x == arreglo[i]){
            printf("El número %d se encuentra en la posición %d del arreglo. \n", arreglo[i], i);
            return 0;
        } 
    }
    printf("El número %d no se encuentra en el arreglo. \n", x);
    return 0;
}