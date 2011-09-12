#include <stdio.h>
#include "link.h"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    List head;
    head = init();
    createList(arr, len, head);
    display(head);
    
    return 0;
    }
