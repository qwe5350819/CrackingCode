#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//ctrl+b for compile
//ctrl+shift+b for exe
/*
Implement an algorithm to find the nth to last element 
of a singly linked list.
*/


struct node {
    int val;
    struct node * next;
};
// typedef struct node node_t;


void print_list(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%d-> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(node * head)
{
    node * current = head->next;
    node * remove_prev = head;
    do{
        remove_prev->val = -1;
        free(remove_prev);
        remove_prev = current;
        current = current->next;
    }while(remove_prev->next != NULL);
    remove_prev->val = -1;
    free(remove_prev);
}


//add to the end of linked list
void push(node * head, int val) {
    node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (struct node *)malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
}

int getnthToLast(node * head , int nth) {
    node * current = head;
    int length;

    //find length
    for (int i = 0; current!=NULL; ++i)
    {
        length = i;
        current = current->next;
    }

    //find length - nth 
    current = head;
    for (int i = 0; i < length-nth+1 ; ++i)
    {
        current = current->next;
    }
    return current->val;
}

int main() {

    //set up linked list 
    struct node * list = (struct node *)malloc(sizeof(struct node));
    list->val = rand()%10;
    list->next = NULL;
    for (int i = 0; i < 20; ++i)
        push(list,rand()%10);
    print_list(list);

    //start removing
    
    printf("%d\n",getnthToLast(list,1));
    free_list(list);
    system("PAUSE");
    return 0;
}