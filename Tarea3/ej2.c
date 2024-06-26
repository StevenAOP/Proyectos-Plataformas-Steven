#include <stdio.h>
#include <stdlib.h> // Se agregó


int factorial(int n){
    int i = 1;
    // Lógica: Se mutiplica por n*(n-1)*(n-2)*...*(n-n+1)
    while(n > 1){
        i = i * n;
        n = n - 1; // Corrección (n se define antes)
    }
    return i;
}

int main(int arge, char *argv[]){
    int num = atoi(argv[1]); // Se agregó para que lea el número ingresado
    int fac = factorial(num); // Corrección
    printf("El factorial de %d es: %d\n", num, fac); // Modificacción
    return 0;
}