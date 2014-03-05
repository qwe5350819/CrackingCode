#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//ctrl+b for compile
//ctrl+shift+b for exe

struct node 
{
    int val;
    struct node * next;
};
// typedef struct node node_t;

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


//add to the end of linked list, return the last element
struct node * push(node * head, int val) 
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
    return current->next;
}

struct node * addlist(node * add1 , node * add2) 
{
    node * current1 = add1;
    node * current2 = add2;
    node * resultlist = (struct node *)malloc(sizeof(struct node));
    node * resulttail;
    bool overten = false;
    int sum;

    //adding
    sum = current1->val + current2->val;
    if (sum>10)
        overten = true;
    resultlist->val = sum%10;
    resultlist->next = NULL;
    current1 = current1->next;
    current2 = current2->next;
    while (current1!=NULL && current2!=NULL) 
    {
        sum = current1->val + current2->val;
        if (overten)
        {
            sum++;
            overten = false;            
        }
        if (sum>10)
            overten = true;
        resulttail = push(resultlist,sum%10);
        current1 = current1->next;
        current2 = current2->next;
    }
    if (overten)
    {
        push(resultlist,1);
    }
    return resultlist;
}

int main() {

    //set up linked list 
    struct node * list1 = (struct node *)malloc(sizeof(struct node));
    list1->next = NULL;
    list1->val = rand()%10;
    for (int i = 0; i < 2; ++i)
        push(list1,rand()%10);
    struct node * list2 = (struct node *)malloc(sizeof(struct node));
    list2->next = NULL;
    list2->val = rand()%10;
    for (int i = 0; i < 2; ++i)
        push(list2,rand()%10);

    print_list(list1);
    print_list(list2);

    //start adding
    struct node * result = addlist(list1,list2);
    print_list(result);
    free_list(list1);
    free_list(list2);
    free_list(result);
    system("PAUSE");
    return 0;
}