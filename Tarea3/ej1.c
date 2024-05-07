#include <stdio.h>

int main(){
    // Declarando variables
    int i;
    int num_triangular;
    for(i = 0; i < 100; i++){ // Recorriendo de 0 a 99
        num_triangular= i * (i + 1) / 2; // Evaluando la fórmula
        printf("%d", num_triangular);

        // Coloca las comas a los número para distinguir bien cada número
        if(i < 99){
            printf(",");
        }

        // Imprime una nueva línea cada 5 números para dar un orden
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    return 0;
}