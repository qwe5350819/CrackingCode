#include <iostream>
#include <cstring>
#include <cmath>
#include <list>


using namespace std;
//You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.

//this part is from https://github.com/Hawstein/cracking-the-coding-interview/blob/master/4.3.cpp
//const int maxn = 100;
//struct Node{
//    int key;
//    Node *lchild=NULL, *rchild=NULL, *parent=NULL;
//};
//Node node[maxn];
//int cnt;
//
//void init(){
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

void printPath(Node* n , int length){
	cout<<"<";
	Node* c=n;
	while(length>=0){
		cout<<"-"<<c->key;
		length--;
		c = c->parent;
	}
	cout<<">"<<endl;
}

Node * postOrder(Node* n){
	//left
	if(n->lchild!=NULL && n->lchild->key!=-1){
		return n->lchild;
	}
	//right
	if(n->rchild!=NULL && n->rchild->key!=-1){
		return n->rchild;
	}
	if(n->parent!=NULL && n->parent->key!=-1){
		return n->parent;
	}
	return NULL;
}


//bottom up
bool path( Node* r , int sum){
	Node *cursor = r;
	//find the first leaf node by postorder
	while(true){
		cursor = postOrder(cursor);
		if(cursor->lchild==NULL && cursor->rchild==NULL)
		break;
		if(cursor==NULL)
		break;
	}
	
	//traverse the tree from prvious node
	int csum=0;//current sum
	int cnt=0;
	Node *pathCursor = cursor;
	while(true){//moving between tree nodes
		while(true){//walk through the path
			csum+=pathCursor->key;
			pathCursor = pathCursor->parent;
			
			if(csum>sum){
				cursor->key=-1;
				cnt=0;
				csum=0;
				break;
			}

			if(csum==sum){//print and reset
				printPath(cursor,cnt);
				cursor->key=-1;
				cnt=0;
				csum=0;
				break;
			}
			cnt++;
		}
		cursor = postOrder(cursor);
		pathCursor = cursor;
		if(cursor==NULL || cursor->parent==NULL)
			break;
	}
	
}


int main(){
	int asize = 50,bsize = 5;
	int a[asize],b[bsize];
	for(int i = 0 ; i<asize  ; i++)
		a[i]=i;
	for(int i = 0 ; i<bsize  ; i++)
		b[i]=i;

 	Node *r1 = NULL, *r2 = NULL;
    create_minimal_tree(r1, NULL, a, 0, asize);

	path(r1,7);
	
	return 0;
	
}
