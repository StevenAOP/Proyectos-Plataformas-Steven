#include <stdio.h>
#include <stdlib.h>

#define SIZE 5




int main() {

    int num = solicitud();

    int num_revisado = revision(num);

    matriz(num_revisado);

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

int matriz(int n){
    int matrix[n][n];

    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j <= n; j++){
            matrix[i][j] = rand() % 2;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matrix[i][j] = rand() % 2;
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}