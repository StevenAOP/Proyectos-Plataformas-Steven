#include "stack.h"
#include <stdio.h>

int main(){
    // Inicializando la pila
    Stack stack;
    initStack(&stack);

    // Elaborando una pila con datos e imprimiendo el elemento en la parte superior de la pila
    printf("Apilando un 256, 128, 64, 32, 16\n");
    push(&stack, 256);
    push(&stack, 128);
    push(&stack, 64);
    push(&stack, 32);
    push(&stack, 16);
    printf("En el top de la pila aparce un: %d\n", peek(&stack));

    printf("\nEstado de la pila. \nVacía: %s\n", isEmpty(&stack) ? "Sí" : "No");

    printf("\nEliminando: %d\n", pop(&stack));
    printf("En el top de la pila aparce un: %d\n", peek(&stack));

    printf("\nLiberando memoria.\n");
    freeStack(&stack);

    printf("\nEstado de la pila. \nVacía: %s\n", isEmpty(&stack) ? "Sí" : "No");    

    return 0;
}
