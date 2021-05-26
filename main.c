#include <stdio.h>
#include "BST.h"
#include "Heap.h"

int main() {
    printf("Kaki\n");
    printf("SziaKaki");
    MAXHEAP heap;
    heap=CreateMax_Heap();
    insert_Heap(&heap, 5);
    insert_Heap(&heap, 7);
    printArray_Heap(heap);
    return 0;
}
