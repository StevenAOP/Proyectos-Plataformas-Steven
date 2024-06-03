#include <stdio.h>
#include "double_list.h"

int main(){
    Node * head = NULL;

    insertBeginning(5, &head);

    freList(head);
}