#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/*
 * Esta función inserta un nodo al inicio de la lista.
 * @param data El número a insertar.
 * @param head Puntero al puntero referencia del inicio de la lista
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
 * Esta función inserta un nodo al inicio de la lista.
 * @param data El número a insertar.
 * @param head Puntero al puntero referencia del inicio de la lista
*/
void insertEnd(int data, Node** head){
    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Fallo reservando memoria\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


/*
 * Esta función inserta un nodo al inicio de la lista.
 * @param data  El número a insertar.
 * @param index El índice donde se insertará el número.
 * @param head  Puntero al puntero referencia del inicio de la lista
*/
void insertar_por_Indice(int data, int index, Node** head) {
    if (index == 0) {
        insertBeginning(data, head);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fallo reservando memoria\n");
        return;
    }

    // Se asigna el valor al nuevo nodo
    newNode->data = data;

    // Recorre la lista hasta el nodo anterior de la posición deseada
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    // Verifica que el índice esté dentro de la lista
    if (temp == NULL || temp->next == NULL) {
        printf("Indice mayor que la lista\n");
        free(newNode);
        return;
    }

    // Se inserta el nuevo nodo
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}


/*
 * Esta función elimina un nodo apartir de un dato de la lista dado.
 * @param data  El número a buscar para eliminar el nodo.
 * @param head  Puntero al puntero referencia del inicio de la lista
*/
void eliminarNode(int data, Node** head) {
    Node* temp = *head;

    // Se recorre la lista para encontrar el número
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("El nodo del dato %d no se encuentra en la lista\n", data);
        return;
    }

    // Se elimina el nodo del número encontrado
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}


/*
 * Esta función busca el nodo de una dato dado.
 * @param data  El número a buscar para indicar el nodo.
 * @param head  Puntero referencia del inicio de la lista
*/
void buscaNode(int data, Node* head) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
        index++;
    }
    if (temp!= NULL) {
        printf("\nEl nodo encontrado del dato es: %d\n", index);
    } else {
        printf("\nDato no encontrado\n");
    }
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


/*
 * Esta función recorre la lista hacia atrás y la imprime.
 * @param head Puntero referencia del inicio de la lista
*/
void atrasImprimir(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
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