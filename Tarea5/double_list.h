#ifndef double_list_h
#define double_list_h

// Definición del nodo
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Declaración de la funciones
void insertBeginning(int data, Node** head);
void adelanteImprimir(Node* head);
void freeList(Node* head);
#endif