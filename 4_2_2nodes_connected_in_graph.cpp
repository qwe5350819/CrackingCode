#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void setatob(int a , int b , bool graph[50][50]){
	graph[a][b]=true;
}

void printTable(bool g[50][50]){
	for(int i = 0 ; i < 50 ; i++){
		for(int j = 0 ; j < 50 ; j++){
			if(g[i][j]==true){
			cout<<"t";
			}else{
				cout<<"f";
			}
		}
		cout<<endl;
	}
		cout<<endl;
		cout<<endl;
		cout<<endl;
	
}


bool isAconnectB(int a , int b , bool g[50][50], bool f[50][50]){
	for(int i = 0 ; i < 50 ; i++){
		if(g[a][b]==true){
			cout<<a<<"->"<<b<<" is good"<<endl;
			return true;
		}else if(g[a][i]==true) {
			isAconnectB[i][b];
		}
	}	
	return false;
}

int main(){
	srand((unsigned)time(0));
	bool graph[50][50];
	bool footprint[50][50];
	
	for(int i = 0 ; i < 500 ; i++){
		setatob(rand()%50,rand()%50,graph);
	}
	
	for(int i = 0 ; i < 50 ; i++){
		for(int j = 0 ; j < 50 ; j++)	{
			footprint[i][j]=false;
		}
	}
	
	int a=rand()%50,b=rand()%50;
	cout<<"check "<<a<<b<<endl;
	if(isAconnectB(a,b,graph,footprint)){
		cout<<"connected"<<endl;
	}else{
		cout<<"not connected"<<endl;
	}
	
	printTable(graph);
	
}
