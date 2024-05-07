#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de la funcióones
int solicitud();
int revision();
int findLargeSquare();
int minimo(int x, int y, int z);

int main() {
    // Se llama la función para solicitar el tamaño de la matriz cuadrada
    int num = solicitud();

    // Se llama a la funcións que revisa el número ingresado
    int SIZE = revision(num);

    printf("La matriz utilizada corresponde a:\n");
    
    // Se llama a la función que crea la matriz nxn con números aleatorios
    findLargeSquare(SIZE);

    return 0;
}


// FUNCIONES
int solicitud() {
    int n; // declarando n
    printf("Ingrese el número de filas de la matriz nxn: ");
    scanf("%d", &n); // Leyendo lo ingresado por el usuario
    return n;
}


int revision(int i){
    if ((i>=1) & (i<=10)){ // Revisando que i este entre 1-10 
        return i;          // Se retorna i si esta entre 1-10
    }
    else{ // Si no se cumple el if se retorna 6 para hacer la matriz
        return i = 6;
    };
}


int minimo(int x, int y, int z) {
    if (x < y) {
        return x < z ? x : z; // Devuelve el número más pequeño entre x, z
    } else {
        return y < z ? y : z; // Devuelve el número más pequeño entre y, z
    }
}


int findLargeSquare(int SIZE) {
    int matrix[SIZE][SIZE];
    // Matriz para almacenar el tamaño de los cuadrados que se vayan encontrando
    int matrix_almacenar[SIZE][SIZE];
    // Se inicia las variables en 0
    int i, j, tamaño_max = 0;
    srand(time(NULL));  // Generar números aleatorios a partir del tiempo

    // Se crea y muestra la matriz de números binarios
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2; // Agregando un binario aleatorio a matrix[i][j]
            printf("%d ", matrix[i][j]);

            // Estra para la primera fila o columna, evitando así las fronteras
            if (i == 0 || j == 0) 
                matrix_almacenar[i][j] = matrix[i][j]; // Almacenado las fronteras en matriz_almacenar

            // Entra si se encuentra un 1, revisa a sus alrededores para atrás y se añmacena si se encontró un cuadrado o si se sugue con 1
            else if (matrix[i][j] == 1)
                matrix_almacenar[i][j] = minimo(matrix_almacenar[i-1][j], matrix_almacenar[i][j-1], matrix_almacenar[i-1][j-1]) + 1;
            
            // Si se encuentra un cero simplemente se almacena así en matrix_almacenar
            else
                matrix_almacenar[i][j] = 0;
            
            // Actualizando el tamaño máximo del cuadrado encontrado
            if (matrix_almacenar[i][j] > tamaño_max)
                tamaño_max = matrix_almacenar[i][j];
        }
        printf("\n");
    }

    printf("El tamaño del cuadrado más grande de unos es: %dx%d.\n", tamaño_max, tamaño_max);
    return 0;
}

