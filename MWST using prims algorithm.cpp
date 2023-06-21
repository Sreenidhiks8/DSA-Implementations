#include <iostream>
#include <limits>
#define MAXSIZE 10
using namespace std;
struct node{
int ver;
int weight;
node *next;
};
struct vertex{
string name;
bool inTree;
int key;
int par;
node *adjptr;
};
class Graph{
vertex G[10];
int n;

public:
void createGraph(){
cout << "Enter no. of vertices: ";
cin >> n;
for (int i=0; i<n; i++){
int m;
cout << "Enter name of the vertex: ";
cin >> G[i].name;
cout << "Enter no. of adjecent vertices for vertex " << G[i].name << endl;
cin >> m;
G[i].adjptr = NULL;
for (int j=0; j<m; j++){
node *t = new node;
cout << "Enter index of adjacent vertex - " << j << ": ";
cin >> t->ver;
cout << "Enter weight of the edge: ";
cin >> t->weight;
t->next = G[i].adjptr;
G[i].adjptr = t;
}
}
}

void display(){
for (int i=0; i<n; i++){
cout << G[i].name << "  ";
cout << G[i].inTree << " ";
node *t = G[i].adjptr;
while (t!=NULL){
cout << "-->(" << t->ver << ", " << t->weight << ") ";
t = t->next;
}
cout << endl;
}

}

void MWST_Prims(){
int v, total = 0;
for (int i=0; i<n; i++){
G[i].inTree = false;
G[i].key = INT_MAX;
G[i].par = -1;
}
G[0].key = 0;
cout << "Edges included in the spanning tree are: " << endl;
for (int i=0; i<n; i++){
int minkey = INT_MAX;
for (int j=0; j<n; j++){
if (!G[j].inTree && minkey > G[j].key){
minkey = G[j].key;
v = j;
}  
}
if (G[v].par != -1){
    cout << G[G[v].par].name << "-->" << G[v].name << ": " << G[v].key <<endl;
    total = total + G[v].key;
}
G[v].inTree = true;
node *t = G[v].adjptr;
while (t != NULL){
int u = t->ver;
if (!G[u].inTree && t->weight < G[u].key){
G[u].key = t->weight;
G[u].par = v;
}
t = t->next;
}
}
cout << "Spanning Tree Total Weight: " << total << endl;
}
};
int main(){
Graph graph;
int s;
graph.createGraph();
graph.MWST_Prims();
cout << "Graph: " << endl;
graph.display();
return 0;
}

