#include<iostream>
#include<stdio.h>
#include<limits>
#include<fstream>
using namespace std;
class matrix_chain_multiplication
{
 int M[20][20];
 int S[20][20];
 int P[20];
 public:
 void readinput(int n)
 {
  ifstream fin("INPUT1_9.txt");
  for(int i=0;i<=n;i++)
  {
   fin>>P[i];
  }
  fin.close();
 }
 void initialization(int a,int b)
 {
  for(int i=1;i<=b;i++)
  {
   for(int j=1;j<=b;j++)
   {
    M[i][j]=INT_MAX;
    S[i][j]=0;
   }
  }
 }
 int recursive_matrix_chain_WOM(int i,int j,int &count)
 {
  if(i==j)
  {
   return 0;
  }
  int q=0;
  for(int k=i;k<=j-1;k++)
  {  
   count++;
   q=(recursive_matrix_chain_WOM(i,k,count) + recursive_matrix_chain_WOM(k+1,j,count) + P[i-1]*P[k]*P[j]);
   if(M[i][j] > q)
   {
   M[i][j] = q;
   S[i][j] = k;
   }
  }
  return M[i][j];
 }
 int LOOK_UP_CHAIN(int i,int j,int &count)
 {
  int q=0;
  if(M[i][j] < INT_MAX)
  {
   return M[i][j];
  }
  if(i==j)
  {
   M[i][j]=0;
  }
  else
  {
   for(int k=i;k<=j-1;k++)
   {
    count++;
    q=LOOK_UP_CHAIN(i,k,count) + LOOK_UP_CHAIN(k+1,j,count) + P[i-1]*P[k]*P[j];
    if(q<M[i][j])
    {
     M[i][j]=q;
     S[i][j]=k;
    }
   }
  }
  return M[i][j];
 }
	
 int MEMOIZED_MATRIX_CHAIN(int n,int &count)
 {
  //int n;
  //n=P.length() - 1;
  for(int i=1;i<=n;i++)
  {
   for(int j=i;j<=n;j++)
   {
    M[i][j]=INT_MAX;
    S[i][j]=0;
   }
  }
  return LOOK_UP_CHAIN(1,n,count);
 }
 int MCM_BU_WM(int n,int &count)
 {
  int i,j;
  for(i=1;i<=n;i++)
  {
   count++;
   M[i][i]=0;
   S[i][i]=0;
  }
  for(int l=2;l<=n;l++)
  {
   count++;
   int q;
   for(i=1;i<=(n-l+1);i++)
   {
    count++;
    j=i+l-1;
    M[i][j]=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
     count++;
     q=M[i][k] + M[k+1][j] + P[i-1]*P[k]*P[j];
     if(q<M[i][j])
     {
      M[i][j]=q;
      S[i][j]=k;
     }
    }
   }
  }
  return M[i][j];
 }
	
 void PRINT_optimal_pares(int i,int j)
 {
  if(i==j)
  {
   cout<<"A"<<i;
  }
  else
  {
   cout<<"(";
   PRINT_optimal_pares(i,S[i][j]);
   PRINT_optimal_pares(S[i][j]+1,j);
   cout<<")";
  }
 }
};
int main()
{
 int value;
 matrix_chain_multiplication obj;
 int len[]={3,4,5,10,15,19};
 int n;
 int count;
 cout<<"Without memoization"<<endl;
 for(int a=0;a<6;a++)
 {
  count=0;
  n=len[a];
  obj.readinput(n);
  obj.initialization(1,n);
  value=obj.recursive_matrix_chain_WOM(1,n,count);
  obj.PRINT_optimal_pares(1,n);
  cout<<endl;
  cout<<"value : "<<value<<" "<<"count : "<<count<<endl;
 }
 cout<<endl<<"with memoization"<<endl;
 for(int a=0;a<6;a++)
 {
  count=0;
  n=len[a];
  obj.readinput(n);
  obj.initialization(1,n);
  value=obj.MEMOIZED_MATRIX_CHAIN(n,count);
  obj.PRINT_optimal_pares(1,n);
  cout<<endl;
  cout<<"value : "<<value<<" "<<"count : "<<count<<endl;
 }
 cout<<endl<<"Bottom-up approach"<<endl;
 for(int a=0;a<6;a++)
 {
  count=0;
  n=len[a];
  obj.readinput(n);
  obj.initialization(1,n);
  value=obj.MCM_BU_WM(n,count);
  obj.PRINT_optimal_pares(1,n);
  cout<<endl;
  cout<<"value : "<<value<<" "<<"count : "<<count<<endl;
 }
}
