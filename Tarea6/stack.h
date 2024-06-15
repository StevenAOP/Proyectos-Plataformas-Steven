#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Estructura para el nodo de la pila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estructura para la pila
typedef struct Stack {
    Node* top;
} Stack;


// Declaración de Funciones
void initStack(Stack* stack);
void push(Stack* stack, int data);
int peek(Stack* stack);
bool isEmpty(Stack* stack);

#endif