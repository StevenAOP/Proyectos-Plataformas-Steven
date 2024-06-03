#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"


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

void freList(Node* head){
    Node * actual = head;
    Node * next;
    while (actual != NULL){
        next = actual->next;
        free(actual);
        actual = next;
    }
}