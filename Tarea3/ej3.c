#include <stdio.h>

#define SIZE 5




int main() {

    int num = solicitud();

    int num_revisado = revision(num);

    return 0;
}



// FUNCIONES
int solicitud() {
    int n;
    printf("Ingrese el número de filas de la matriz nxn: ");
    scanf("%d", &n);
    return n;
}

int revision(int i){
    if ((i>=1) & (i<=10)){
        return i;
    }
    else{
        return i = 6;
    };
}

