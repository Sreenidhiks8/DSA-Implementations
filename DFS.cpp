#include <iostreaam>
using namespace std;
#define MAXSIZE 100

struct adjlist{
	int ver;		//index of each vertex
	adjlist *next;		//ptr to the next node
};

struct vertex{
	string name;		//name of the vertex
	bool processed;		//whether its processed or not
	adjlist *first;		//ptr to the first node of the adjacency list
};

class Stack{
	Stack(){
		top=-1;
	}
	
	bool isEmpty(){
		if(top==-1)
			return true;
		else 
			return false;
	}
	
	bool isFull(){
		if(top==MAXSIZE-1)
			return true;
		else 
			return false;
	}
	
	bool pushStack(int val){
		if(isFull())
			return false;
		else
			arr[top++]=val;
			return true;
	}
	
	bool popStack(int val){
			val=arr[top];
			arr[top]=0;
			top--;
			return true;
		}
	
};

class Graph{
	vertex G[10];
	int n;
	public:
		void createGraph(){
			cout << "No. of vertices: ";
			cin >> n;		//total no of vertices
			for (int i=0; i<n; i++){
				int m, ind;		//m is the no of adj vertices and ind is its index
				cout << "Enter name of the vertex: ";
				cin >> G[i].name;
				cout << "Enter no. of adjacent vertices to "<< G[i].name<<endl;
				cin >> m;
				G[i]->first = NULL;
				for (int j=0; j<m; j++){
					cout << "Enter the index of adjacent vertex - "<< j <<": ";
					cin >> ind;
					adjlist *T = new adjlist;
					T->ver = ind;
					T->next = G[i]->first;
					G[i]->first = T;
				}
			}
};

class DFS(int s){
	int i=0;
	while(i<n){
		G[i].processed=false;
		i++;
	}
	Stack stk;
	i=0;
	while(i<n){
		if(G[i].processed==false)
			s.pushStack(i);
			while(!stk.isEmpty())
				s.popStack(i)
	}
	
};



