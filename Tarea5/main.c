#include <stdio.h>
#include "double_list.h"

int main(){
    Node * head = NULL;
    
    printf("Creando lista insertando nodos al inicio y al final e imprimiendo hacia adelante\n");
    insertBeginning(0, &head);

    // Se rellena la lista con [2, 4, 6, 8, 10]
    for (int i = 2; i < 12; i++){
        insertEnd(i, &head);
        i++;
    }
    adelanteImprimir(head);

    printf("\nSe inserta un nuevo dato en el índice 3\n");
    // Insertar un nuevo dato y mostrarlo
    insertar_por_Indice(7, 3, &head);
    adelanteImprimir(head);

    printf("\nSe elimina el nodo del dato 7\n");
    // Se elimina un nodo en base a un dato dado y se imprime
    eliminarNode(7, &head);
    adelanteImprimir(head);

    printf("\nSe imprime la lista que se recorre hacia atrás\n");
    atrasImprimir(head);

    freeList(head);
}