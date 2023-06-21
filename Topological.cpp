#include<iostream>

using namespace std;

struct node
{
int ver;
node *next;
};

struct headnode
{
int count;
node *link;
};

headnode * h;
struct vertex
{
int index,d,f,pi;
char color, name;
node *adjptr;
};

class depth_first
{
vertex g[10];
int n,m,time;
public:
depth_first()
{
h=new headnode;
h->link=NULL;
}
void get()
{
cout<<"Enter no of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
{
g[i].index=i;
cout<<"Enter the name of vertex:";
cin>>g[i].name;
g[i].color='w';
g[i].pi=0;
g[i].adjptr=NULL;
cout<<"Enter the no of adjacent vertices:";
cin>>m;
cout<<"Enter adjacent vertices:";
for(int j=1;j<=m;j++)
{
node* t=new node;
cin>>t->ver;
t->next=g[i].adjptr;
g[i].adjptr=t;
}
cout<<endl;
}
time=0;
for(int i=1;i<=n;i++)
{
if(g[i].color=='w')
{
dfs(i);
}
}
}

void dfs(int u)
{
time=time+1;
g[u].d=time;
g[u].color='g';
node * v=g[u].adjptr;
while(v!=NULL)
{
if(g[v->ver].color=='w')
{
g[v->ver].pi=g[u].index;
dfs(v->ver);
}
v=v->next;
}
time=time+1;
g[u].f=time;
g[u].color='b';
node * pnew=new node;
pnew->ver=u;
pnew->next=h->link;
h->link=pnew;
}

void display()
{
cout<<"Enter name"<<"\t"<<"d"<<"\t"<<"f"<<"\t"<<"color"<<endl;
for(int i=1;i<=n;i++)
{
cout<<g[i].index<<"\t "<<g[i].name<<"\t "<<g[i].d<<" \t";
cout<<g[i].f<<"\t "<<g[i].color<<endl;
}
}

void topo_sort()
{
node *walker=h->link;
while(walker!=NULL)
{
cout<<g[walker->ver].name<<" ";
walker=walker->next;
}
}
};


int main()
{
depth_first df;
df.get();
df.display();
cout<<"Topological sort:"<<endl;
df.topo_sort();
}
