#include<iostream>
#include <fstream>
using namespace std;

class Node{
	public :
		Node* leafl;
		Node* leafr;
		Node* faternode;
		
		Node(int);
		int getKey();
		void setKey(int);
	private:
		int key;//=-1;
};

Node::Node(int intKey){
	key=intKey;
	leafl = NULL;
	leafr = NULL;
	faternode = NULL;
}

int Node::getKey(){
	return key;
}

void Node::setKey(int k){
	key = k;
}

Node* Tree(int a[] , int min, int max){
	int end=0;
	int start = 0 ;
	while(a[end]!=max){
		end++;
	}
	while(a[start]!=min){
		start++;
	}
	
	int len = end-start;
	int mid;
	if(len>0){
		mid = len/2;
	}else if (len==0){
		mid = 0;
	}else{
		return NULL;
	}
	 
	Node root(a[start+mid]) ;
	
	cout<<a[start+mid] << " added "<<endl;
	
	if(len>0){
			root.leafl = Tree(a,min,a[start+mid-1]);
			root.leafr = Tree(a,a[start+mid+1],max);
	}
	
	return &root;
	
}

int main(){
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	Tree(a, 0,9);
	return 0 ; 
}

