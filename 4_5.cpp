#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//Write an algorithm to find the ¡¥next¡¦ node (i.e., in-order successor) of a given node in a binary search tree where each node has a link to its parent.

//this part is from https://github.com/Hawstein/cracking-the-coding-interview/blob/master/4.3.cpp
//const int maxn = 100;
//struct Node{
//    int key;
//    Node *lchild, *rchild, *parent;
//};
//Node *p, node[maxn];
//int cnt;
//
//void init(){
//    p = NULL;
//    memset(node, '\0', sizeof(node));
//    cnt = 0;
//}
//void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
//    if(start <= end){
//        int mid = (start + end)>>1;
//        node[cnt].key = a[mid];
//        node[cnt].parent = parent;
//        head = &node[cnt++];
//        create_minimal_tree(head->lchild, head, a, start, mid-1);
//        create_minimal_tree(head->rchild, head, a, mid+1, end);
//    }
//}
//int height(Node *head){
//    if(head == NULL) return 0;
//    return max(height(head->lchild), height(head->rchild)) + 1;
//}



Node* successor( Node* root){
	if(root==NULL)
		return NULL;

	//return right leaf	
	if(root->rchild!=NULL){
		return root->rchild;
	}

	//return father leaf
	if(root->parent!=NULL){
		return root->parent;
	}
	
	return NULL;	
}







int main(){
	int a[] = {0,1,2,3,4,5,6,7,8,9};

    init();
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 9);
    cout<<head->key<<endl;
	cout<<	successor(head)->key;
	
	system("pause");
	return 0;
	
}
