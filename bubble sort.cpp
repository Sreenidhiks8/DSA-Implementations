#include <iostream>
using namespace std;

void bubble(int arr[], int n){
	for(int i=0;i<n-1;i++){  //accessing each arr element
		for(int j=0;j<n-i-1;j++){    //to compare array elements
			if (arr[j]>arr[j+1]){    //swapping of elements
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void printarr(int arr[],int n){    //printing array elements
	for(int i=0;i<n;i++){
		cout<<"  "<<arr[i];
	}
	
}

int main(){
	int arr[20],n;
	cout<<"enter the size of the array: "<<endl; cin>>n;
	//n=sizeof(arr)/sizeof(arr[0]);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubble(arr,n);
	cout<<"array in ascending order is: "<<endl;
	printarr(arr,n);	
}
