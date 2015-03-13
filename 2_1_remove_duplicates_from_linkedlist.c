#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//ctrl+b for compile
//ctrl+shift+b for exe
/*
Write code to remove duplicates from an unsorted linked 
list. FOLLOW UP How would you solve this problem if a 
temporary buffer is not allowed?
*/


struct node {
    int val;
    struct node * next;
};


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

void remove_duplicated(node * head) {
    node * checked = NULL;
    node * current = NULL;
    node * prev = NULL;
    int val ;

    //walk through the list
    checked = head;//make sure checked->val is unique
    while(checked->next!=NULL)
    {
        prev = checked;
        val = checked->val;
        current = checked->next;

        //remove duplicated element 
        while(current->next != NULL)//check list except the last one
        {
		//remove node
            if(current->val == val)
            {
                prev->next = current->next;
                current->val = -1;
                free(current);
                current = prev->next;
            }else
            {//move to next node
                prev = current;
                current = current->next;
            }
        }
        //check the last element, current = the last one
        if(current->val == val)
            {
                prev->next = current->next;
                current->val = -1;
                free(current);
                current = prev->next;
            }
        checked = checked->next;
    }

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
    remove_duplicated(list);
    print_list(list);
    free_list(list);
    system("PAUSE");
    return 0;
}