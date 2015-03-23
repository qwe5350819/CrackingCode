#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//You have two very large binary trees: T1, with millions of nodes, and T2, with hun- dreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.

//this part is from https://github.com/Hawstein/cracking-the-coding-interview/blob/master/4.3.cpp
const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node node[maxn];
int cnt;

void init(){
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}


bool match(Node * t1, Node * t2){
	if(t1==NULL&&t2==NULL){
		return true;
	}else if(t1==NULL||t2==NULL){
		return false;
	}
	
	if(t1->key==t2->key){
		return match(t1->lchild,t2->lchild)&&match(t1->rchild,t2->rchild);
	}
	
	return false;
	
}

bool isSubtree( Node* t1 , Node* t2 ){
	if(t1==NULL || t2==NULL){
		return false;
	}
	
	if(match(t1,t2)){
		return true;
	}
	
	return isSubtree(t1->lchild,t2) || isSubtree(t1->rchild,t2);
}


int main(){
	int asize = 10,bsize = 5;
	int a[asize],b[bsize];
	for(int i = 0 ; i<asize  ; i++)
		a[i]=i;
	for(int i = 0 ; i<bsize  ; i++)
		b[i]=i;

 	Node *r1 = NULL, *r2 = NULL;
    create_minimal_tree(r1, NULL, a, 0, 6);
    create_minimal_tree(r2, NULL, b, 0, 2);
		
	if(isSubtree(r1,r2)){
		cout<<"match"<<endl;
	}
	
	return 0;
	
}
