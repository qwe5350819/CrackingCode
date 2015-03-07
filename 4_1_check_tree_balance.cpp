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

bool checkNeibor(Node n){
	
	if(n.faternode!=NULL){
		
		if(n.faternode->leafl!=NULL
		&&n.faternode->leafr!=NULL){
			
			if(n.faternode->leafr!=&n){
				if(n.faternode->leafr->getKey()!=-1)
					return true;
				return false;
			}else{
				if(n.faternode->leafl->getKey()!=-1)
					return true;
				return false;
			}
		}
	
	}
	
	return false;
}

bool checkBalance(Node *tree_root){
	int max =0 , min =99;
	
	int dist=0;
	while(true){
		step:
		
		//bottom leaf
		if(tree_root->leafl==NULL && tree_root->leafr==NULL){
			
			if(max<dist)
			max = dist;
			if(min>dist)
			min = dist;
			
			if(tree_root->faternode->getKey()==-1){
				break;
			}
		}
					
			
			
		
		//¥ª¥k¤W
		if(tree_root->leafl!=NULL&&tree_root->leafl->getKey()!=-1){
			tree_root = tree_root->leafl;
			dist++;
			
			goto step;
		}
		
		
		if (tree_root->leafr!=NULL&&tree_root->leafr->getKey()!=-1){
			tree_root = tree_root->leafr;
			dist++;
			goto step;
		}
		
		
		if (tree_root->faternode!=NULL&&tree_root->faternode->getKey()!=-1){
			tree_root->setKey(-1);
			tree_root = tree_root->faternode;
			dist--;
			
			goto step;
		}
		
		if(tree_root->faternode==NULL){
			break;
		}
		
	}
	
	if(max-min>1){
		return false;
	}
	return true;
}



int main(){
	//balanced tree	
	Node root(0) ;
	Node l(1) ;
	Node r(2) ;
	
	root.leafl = &l;
	root.leafr = &r;
	r.faternode = &root ; 
	l.faternode = &root;
	
	
	
	//unbalanced tree
	Node ll(5),lll(7);
	root.leafl->leafl = &ll;
	root.leafl->leafl->faternode = root.leafl;
	root.leafl->leafl->leafl = &lll;
	root.leafl->leafl->leafl->faternode = root.leafl->leafl;
	
	
	bool isBalance = checkBalance(&root);
//	isBalance = checkBalance(&root);
	if(isBalance==true){
		cout<<"true"<<endl;
	}else if (isBalance==false){
		cout<<"false"<<endl;
	}
	
	
	system("pause");
	return 0 ; 
}

