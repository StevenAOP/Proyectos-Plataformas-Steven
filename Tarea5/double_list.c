#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/*
 * Esta función inserta un nodo al inicio de la lista.
 * @param data El número a insertar.
 * @param head Puntero referencia del inicio de la lista
*/
void insertBeginning(int data, Node** head){
    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Fallo reservando memoria\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

/*
 * Esta función recorre la lista hacia adelante y la imprime.
 * @param head Puntero referencia del inicio de la lista
*/
void adelanteImprimir(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head){
    Node * actual = head;
    Node * next;
    while (actual != NULL){
        next = actual->next;
        free(actual);
        actual = next;
    }
}