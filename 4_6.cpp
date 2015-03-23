#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

//this part is from https://github.com/Hawstein/cracking-the-coding-interview/blob/master/4.3.cpp
const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;

void init(){
    p = NULL;
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
int height(Node *head){
    if(head == NULL) return 0;
    return max(height(head->lchild), height(head->rchild)) + 1;
}

bool isFather(Node* nodeA,Node* nodeB){
	if(nodeB!=NULL && nodeA!=NULL){
		if(nodeA->key==nodeB->key){
			return true;
		}
		return isFather(nodeA->lchild,nodeB)||isFather(nodeA->rchild,nodeB);
	}
	return false;
}

Node* commonAncestor( Node* nodeA , Node* nodeB ){
	while(nodeA!=NULL){
		if(isFather(nodeA,nodeB)){
			return nodeA;
		}else{
			nodeA=nodeA->parent;
		}
		
	}

	return NULL;
}


int main(){
	int a[] = {0,1,2,3,4,5,6,7,8,9};

    init();
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 9);
    
	cout<<head->key<<endl;
	
	Node* n = commonAncestor(head->lchild->lchild,head->lchild);
	if(n!=NULL){
		cout<<n->key<<endl;
	}
	
	system("pause");
	return 0;
	
}
