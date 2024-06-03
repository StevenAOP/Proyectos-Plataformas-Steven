#include <stdio.h>
#include "double_list.h"

int main(){
    Node * head = NULL;

    // Se crea una lista [2, 4, 6, 8, 10, 12]
    insertBeginning(6, &head);
    insertBeginning(4, &head);
    insertBeginning(2, &head);
    insertEnd(8, &head);
    insertEnd(10, &head);
    insertEnd(12, &head);

    insertar_por_Indice(7, 3, &head);
    
    adelanteImprimir(head);
    atrasImprimir(head);

    freeList(head);
}