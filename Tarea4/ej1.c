#include <stdio.h>

// Declaración de la funciones
int solicitud();

int main(){
    int num = solicitud();
    printf("%d \n", num);
    return 0;
}


// Funciones


/*
 * Esta función solicida un número al usuario
 * @return El número ingresado
*/
int solicitud() {
    int n;
    printf("Ingrese un número:");
    scanf("%d", &n); // Leyendo
    return n;
}