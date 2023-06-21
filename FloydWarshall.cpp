#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;
class Warshall{
	int d[10][10];
	int w[10][10];
	int pi[10][10];
	public:
		void inputW(int n){
			cout<<"Enter the weight matrix: "<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cin>>w[i][j];
				}
			}
		}
		void initialize(int n){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j]=w[i][j];
					if(i==j||w[i][j]==1000){
						pi[i][j]=-1;
					}
					else{
						pi[i][j]=i;
					}
				}
			}
		}
		void floyd_warshall(int n){
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(pi[i][k]!=-1 && pi[k][j]!=-1 && d[i][j]>d[i][k]+d[k][j]){
							d[i][j]=d[i][k]+d[k][j];
							pi[i][j]=pi[k][j];
						}
					}
				}
			}
			
		}
		void printop(int n){
			cout<<"D matrix:"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<d[i][j]<<"\t";
				}
				cout<<endl;
			}
			cout<<"Pi matrix:"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<pi[i][j]<<"\t";
				}
				cout<<endl;
			}
			
		}
		
};
int main(){
	Warshall v;
//	v.inputW(5);
//	v.initialize(5);
//	v.floyd_warshall(5);
//	v.printop(5);
	int op;
	while(op!=2){
		cout<<"Enter 1 for floyd warshall and 2 for exit:"<<endl;
		cin>>op;
		switch(op){
			case 1:
				int n;
				cout<<"Enter the number of vertices:";
				cin>>n;
				cout<<endl;
				v.inputW(n);
				v.initialize(n);
				v.floyd_warshall(n);
				v.printop(n);
				break;
				
				case 2:
					break;
					
					default:
						cout<<"INVALID OPTION";
		}
	}  
	return 0;
}
