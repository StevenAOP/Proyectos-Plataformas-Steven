#include <stdio.h>
#include "double_list.h"

int main(){
    Node * head = NULL;

    insertBeginning(5, &head);

    insertEnd(1, &head);

    adelanteImprimir(head);

    freeList(head);
}