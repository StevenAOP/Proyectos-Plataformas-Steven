#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Inicializa la pila.
 * @param stack Un puntero a la estructura Stack que se va a inicializar.
 */
void initStack(Stack* stack) {
    stack->top = NULL;
}

/*
 * Esta función agrega un elemento a la parte superior de la pila.
 * @param stack Un puntero a la estructura Stack.
 * @param data El dato que se va a agregar a la pila.
 */
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Fallo reservando memoria\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

/*
 * Esta función devuelve el elemento en la parte superior de la pila sin eliminar ese dato.
 * @param stack Un puntero a la estructura Stack.
 * @return El dato en la parte superior de la pila.
 */
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}


/*
 * Esta función elimina y devuelve el elemento en la parte superior de la pila.
 * @param stack Un puntero a la estructura Stack.
 * @return El dato eliminado de la parte superior de la pila.
 */
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}


/*
 * Esta función verifica si la pila está vacía.
 * @param stack Un puntero a la estructura Stack.
 * @return True si la pila está vacía nino retorna False.
 */
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}


/*
 * Esta función libera la memoria utilizada por la pila.
 * @param stack Un puntero a la estructura Stack.
 */
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}