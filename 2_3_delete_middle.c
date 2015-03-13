#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
/*
Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node. EXAMPLE Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e
*/


struct node {
    int val;
    struct node * next;
};


void print_list(node * head) 
{
    node * current = head;

    while (current != NULL) 
    {
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
void push(node * head, int val) 
{
    node * current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (struct node *)malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
}

void delete_mid(node * head ) 
{
    node * mid = head;
    node * current = head;
    node * premid = NULL;
    int count=0;

    //find the mean value
    while(current!=NULL)
    {
        if (count%2==1)
        {
            premid = mid;
            mid=mid->next;
        }
        current = current->next;
        count++;
    }
    printf("%d\n", mid->val);

    //remove mid
    premid->next = mid->next;
    mid->val = -1;
    free(mid);


}

int main() {

    //set up linked list 
    struct node * list = (struct node *)malloc(sizeof(struct node));
    list->val = rand()%10;
    list->next = NULL;
    for (int i = 0; i < 10; ++i)
        push(list,rand()%10);
    print_list(list);

    //start removing
    delete_mid(list);
    print_list(list);
    free_list(list);
    system("PAUSE");
    return 0;
}