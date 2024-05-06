#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de la funcióones
int solicitud();
int revision();
int matriz();


int main() {
    // Se llama la función para solicitar el tamaño de la matriz cuadrada
    int num = solicitud();

    // Se llama a la funcións que revisa el número ingresado
    int num_revisado = revision(num);

    // Se llama a la función que crea la matriz nxn con números aleatorios
    matriz(num_revisado);

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


int matriz(int n){
    int matrix[n][n]; // Definiendo la matriz
    int i, j; // Declarando i, j. Que serán los índices a usar en la matriz
    srand(time(NULL));

    // Se crea la matriz
    for(i = 0; i < n; i++){
        for(j = 0; j <= n; j++){
            matrix[i][j] = rand() % 2; // Se agrega un núemero random binario
        }
    }
    for(i = 0; i < n; i++){ // Enseña la matriz creada
        for(j = 0; j < n; j++){
            matrix[i][j] = rand() % 2;
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}