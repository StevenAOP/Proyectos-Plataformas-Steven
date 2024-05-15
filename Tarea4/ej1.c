#include <stdio.h>
#include <math.h>

// Declaración de la funciones
int solicitud();
int busqueda_lineal(int x, int arreglo[]);
int busqueda_binario(int x, int arreglo[], int tamano); 
int busqueda_binario_recursiva(int x, int arreglo[], int tamano, int izq, int der);

int main(){
    int num = solicitud();
    int numeros[] = {2, 4, 6, 23, 56, 79};
    // Calculando el tamaño del arreglo
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    printf("Busqueda Linieal: \n");
    busqueda_lineal(num, numeros);

    printf("Busqueda Binaria: \n");
    busqueda_binario(num, numeros, tamano);

    // Parametros para la función recursiva
    int izq = 0;
    int der = tamano - 1;

    printf("Busqueda Binaria por Recursividad: \n");
    busqueda_binario_recursiva(num, numeros, tamano, izq, der);

    return 0;
}


////***** FUNCIONES ******////

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
            printf("El número %d se encuentra en la posición %d del arreglo. \n \n", arreglo[i], i);
            return 0;
        } 
    }
    printf("El número %d no se encuentra en el arreglo. \n \n", x);
    return 0;
}


/*
 * Esta función busca un número dentro de un arreglo dado con el método búsqueda binaria.
 * @param x El número a buscar
 * @param arreglo[] El arreglo a manipular
 * @param tamano El tamaño del arreglo
 * @return Cero para salir
*/
int busqueda_binario(int x, int arreglo[], int tamano){
    int izq = 0;
    int der = tamano - 1;

    while (izq <= der){
        // Se calcula el indice de la mitad del arreglo
        int mitad_arreglo = floor((izq + der) / 2);

        // Se encuentra el número de ese índice
        int mitad_arreglo_valor = arreglo[mitad_arreglo];

        if (x == mitad_arreglo_valor){
            printf("El número %d se encuentra en la posición %d del arreglo. \n \n", mitad_arreglo_valor, mitad_arreglo);
            return 0;
        }

        if(x < mitad_arreglo_valor){
            // Si el número encontrado es menor al ingresado se disminuye el indice derecha
            der = mitad_arreglo - 1;
        }
        else{
            // Sino se incrementa el indice izquierda
            izq = mitad_arreglo + 1;

        }
    }
    printf("El número %d no se encuentra en el arreglo. \n \n", x);
    return 0;
}


/*
 * Esta función busca un número dentro de un arreglo dado con el método búsqueda binaria.
 * @param x El número a buscar
 * @param arreglo[] El arreglo a manipular
 * @param tamano El tamaño del arreglo
 * @param izq Indice de inicio del arreglo
 * @param der Indice de fin del arreglo
 * @return Cero para salir
*/
int busqueda_binario_recursiva(int x, int arreglo[], int tamano, int izq, int der){
    // Imprime el mensaje cuando se recorrio todo el arreglo y no se encontró x
    if(izq > der){
        printf("El número %d no se encuentra en el arreglo. \n \n", x);
        return 0;
    }

    // Se calcula el indice de la mitad del arreglo
    int mitad_arreglo = floor((izq + der) / 2);

    // Se encuentra el número de ese índice
    int mitad_arreglo_valor = arreglo[mitad_arreglo];

    if (x == mitad_arreglo_valor){
        printf("El número %d se encuentra en la posición %d del arreglo. \n \n", mitad_arreglo_valor, mitad_arreglo);
        return 0;
    }

    if(x < mitad_arreglo_valor){
        // Si el número encontrado es menor al ingresado se disminuye el indice derecha
        der = mitad_arreglo - 1;
    }
    else{
        // Sino se incrementa el indice izquierda
        izq = mitad_arreglo + 1;
    }

    // Recursividad
    return busqueda_binario_recursiva(x, arreglo, tamano, izq, der);
}