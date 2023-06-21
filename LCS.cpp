#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;
class LCS{
	char x[25];
	char y[25];
	int c[25][25];
	int b[25][25];
	public:
		void getip(int m,int n){
//			cout<<"Enter x sequence: "<<endl;
//			for(int i=1;i<m;i++){
//				cin>>x[i];
//			}
//			cout<<"Enter y sequence: "<<endl;
//			for(int i=1;i<n;i++){
//				cin>>y[i];
//			}
	fstream file1("lcs_input.txt",ios::in);
	for(int i=1;i<=m;i++){
		file1>>x[i];
		
	}
	for(int j=1;j<=n;j++){
		file1>>y[j];
	}
	file1.close();
		
		}
		//DYNAMIC PROGRAMMING-BOTTOM UP APPROACH
		void lcs_length_bu(int m, int n, int &h){
			for(int j=0;j<n;j++){
				c[0][j]=0;
			}
			for(int i=0;i<m;i++){
				c[i][0]=0;
			}
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					h++;
					if(x[i]==y[j]){
						c[i][j]=c[i-1][j-1]+1;
						//1 for diagonal arrow
						b[i][j]=1;
					}
					else if(c[i-1][j]>=c[i][j-1]){
						c[i][j]=c[i-1][j];
						//2 for upper arrow
						b[i][j]=2;
					}
					else{
						c[i][j]=c[i][j-1];
						//3 for left arrow
						b[i][j]=3;
					}
				}
			}
			cout<<"Length of the lcs is "<<c[m][n]<<endl;
		}
		//PRINTING LCS
		void print_lcs(int i,int j){
			if(i==0||j==0){
				return;
			}
			if(b[i][j]==1){
				print_lcs(i-1,j-1);
				cout<<x[i]<<" ";
			}
			else if(b[i][j]==2){
				print_lcs(i-1,j);
			}
			else{
				print_lcs(i,j-1);
			}
		}
		//INITIALIZING C ARRAY
		void initialize(int m,int n){
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++){
					c[i][j]=INT_MIN;
				}
			}
		}
		//DYNAMIC PROGRAMMING-TOP DOWN APPROACH
		int lcs_length_td(int i, int j, int &k){
			if(c[i][j]>=0){
				return c[i][j];
			}
			if(i==0||j==0){
				c[i][j]=0;
				return c[i][j];
			}
			k++;
			if(x[i]==y[j]){
				c[i][j]=lcs_length_td(i-1,j-1,k)+1;
				b[i][j]=1;
				return c[i][j];
			}
			else{
				int t1;
				t1=lcs_length_td(i-1,j,k);
				int t2;
				t2=lcs_length_td(i,j-1,k);
				if(t1>=t2){
					c[i][j]=t1;
					b[i][j]=2;
				}
				else{
					c[i][j]=t2;
					b[i][j]=3;
				}
		return c[i][j];
			}
		}
		
		//DIVIDE AND CONQUER METHOD
		int lcs_length_dc(int i, int j, int &z ){
			
			 if(i==0||j==0){
				
				return 0;
			}
			z++;
			if(x[i]==y[j]){
				
				return lcs_length_dc(i-1,j-1,z)+1;
			}
			else{
				int t1;
				t1=lcs_length_dc(i-1,j,z);
				int t2;
				t2=lcs_length_dc(i,j-1,z);
				if(t1>=t2){
					return t1;
				}
				else{
					return t2;
				}
			
			}
		}
	
		
};
int main(){
	LCS l;
//	l.getip(2,9);
//	l.lcs_length_bu(2,9);
//	int v;
////	v=l.lcs_length_dc(7,6);
////l.initialize(5,4);
//	//v=l.lcs_length_td(5,4);
//	//l.print(5,4);
//
//	//cout<<v;
//	//cout<<"LCS is "<<v<<endl;
//	l.print_lcs(2,9);
int op;
int m[5]={5,3,4,5,6};
int n[5]={7,6,3,6,4};
while(op!=4){
	cout<<"Press 1 for dp-bottom up, 2 for dp-top down, 3 for divide and conquer, 4 for exit"<<endl;
	cin>>op;
	for(int i=0;i<5;i++){
		switch(op){
			case 1:
				l.getip(m[i],n[i]);
				int h;
				h=0;
				l.lcs_length_bu(m[i],n[i],h);
				cout<<"The subsequence is ";
				l.print_lcs(m[i],n[i]);
				cout<<endl;
				cout<<"Count is "<<h<<endl;
				break;
				
				case 2:
					l.getip(m[i],n[i]);
					int k;
					k=0;
					l.initialize(m[i],n[i]);
					cout<<"The length of the lcs is "<<l.lcs_length_td(m[i],n[i],k)<<endl;
					cout<<"Count is "<<k<<endl;
					break;
					
					case 3:
						l.getip(m[i],n[i]);
						int z;
						z=0;
						cout<<"The length of the lcs is "<<l.lcs_length_dc(m[i],n[i],z)<<endl;
						cout<<"Count is "<<z<<endl;
						break;
						
						case 4:
							break;
							default:
								cout<<"Invalid choice:)";
					
		}
	}
}
}
