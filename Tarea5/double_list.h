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
void insertEnd(int data, Node** head);
void insertar_por_Indice(int data, int index, Node** head);
void adelanteImprimir(Node* head);
void atrasImprimir(Node* head);
void freeList(Node* head);
#endif