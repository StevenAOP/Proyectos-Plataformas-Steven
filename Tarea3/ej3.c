#include <stdio.h>

#define SIZE 5

int solicitud() {
    int n;
    printf("Ingrese el número de filas de la matriz nxn: ");
    scanf("%d", &n);
    return n;
}



int main() {

    solicitud();

    return 0;
}