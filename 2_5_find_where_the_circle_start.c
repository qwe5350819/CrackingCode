#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
/*Given a circular linked list, implement an algorithm which returns node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list. EXAMPLE input: A -> B -> C -> D -> E -> C (the same C as earlier) output: C
*/

struct node 
{
    bool footprint;
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
//return the last node
struct node * push(node * head, int val) 
{
//find the last node
    node * current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }

//add a node to the last node
    current->next = (struct node *)malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
    current->next->footprint=false;
    return current->next;
}

//trace from the beginning of this list to the last, the fist node which is traversed twice is the beginning of the loop
int findCircle(node * linkedlist) 
{
    node * current = linkedlist;
    while(current->next!=NULL)
    {
        if(current->footprint == false)
        {
            current->footprint = true;
            current = current->next;
        }else {
            return current->val;
        }
    }
}

int main() {

    //set up linked list 
    struct node * list1 = (struct node *)malloc(sizeof(struct node));
    list1->next = NULL;
    list1->footprint=false;
    list1->val = rand()%10;
    for (int i = 0; i < 10; ++i)
        push(list1,rand()%10);

    //see the list 
    print_list(list1);

    //get the last element
    node * lastEle = list1;
    while(lastEle->next!=NULL)
    {
        lastEle=lastEle->next;
    }
    printf("The Last Element: %d\n",lastEle->val);


    //get random element
    node * randEle = list1;
    for (int i = 0; i < 6; ++i)
    {
        randEle=randEle->next;
    }
    lastEle->next = randEle;
    printf("Circle Start From : %d\n", randEle->val);
    


    //start adding
    printf("%d\n", findCircle(list1));

    //remove the circle and clear mem
    lastEle->next=NULL;
    free_list(list1);
    system("PAUSE");
    return 0;
}