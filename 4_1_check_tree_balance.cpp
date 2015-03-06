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
	ofstream myfile;
	myfile.open ("example.txt");
	myfile << "checkNeibor()\n";
	myfile.close();
	
	if(n.faternode!=NULL){
		ofstream myfile;
		myfile.open ("example.txt");
		myfile << "this node is a bottom leaf\n";
		myfile.close();
		
		
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
	
	cout<<"this node is a root"<<endl;
	return false;
}

bool checkBalance(Node *tree_root){
	int max =0 , min = 0;
	
	ofstream myfile;
	myfile.open ("example.txt",ios::app);
	myfile << "checkBalance\n";
	myfile.close();
	
	int dist=0;
	while(true){
		step:
		myfile.open ("example.txt",ios::app);
		myfile << "is it bottom?\n";
		myfile.close();
		
		//bottom leaf
		if(tree_root->leafl==NULL && tree_root->leafr==NULL){
		myfile.open ("example.txt",ios::app);
		myfile << "hit bottom\n";
		myfile.close();				
			
			
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
			myfile.open ("example.txt",ios::app);
			myfile << tree_root->getKey()<<"left\n";
			myfile.close();			
			
			goto step;
		}
		
		
		myfile.open ("example.txt",ios::app);
		myfile << "?goin right\n";
		myfile.close();		
		if (tree_root->leafr!=NULL&&tree_root->leafr->getKey()!=-1){
			tree_root = tree_root->leafr;
			dist++;
			
			myfile.open ("example.txt",ios::app);
			myfile << "right\n";
			myfile.close();				
			goto step;
		}
		
		
//		myfile.open ("example.txt",ios::app);
//		myfile << "?goin up\n";
//		myfile.close();		
		if (tree_root->faternode!=NULL&&tree_root->faternode->getKey()!=-1){
			myfile.open ("example.txt",ios::app);
			tree_root->setKey(-1);
			
			myfile << "up... current key change to "<<tree_root->getKey();
			tree_root = tree_root->faternode;
			dist--;
			
			myfile << "up\n";
			myfile.close();				
			
			goto step;
		}
		
		myfile.open ("example.txt",ios::app);
		myfile << "\n\n\nnew round\n";
		myfile.close();
		
		if(tree_root->faternode==NULL){
			break;
		}
		
	}
	
	cout<<"max  is " << max << "   min is "<< min <<endl;
	if(max-min>1){
		return false;
	}
	return true;
}



int main(){
	ofstream myfile;
	myfile.open ("example.txt");
	myfile << "main()\n";
		myfile.close();

	
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

