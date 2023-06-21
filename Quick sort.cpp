#include<iostream>
#include<stdio.h>
#include<cstdlib>   //for pseudorandom no generator
#include<time.h>	//for using time as seed value
#include<fstream> 	//for performing operations for file
#include<string>
#include<sstream>
using namespace std;

//r is last element
//p is first element
int PARTITION(int arr[],int p, int r)
{
    
    int pivot= arr[r];   //last element is set as the key
    int i= (p-1);     
    for(int j=p;j<r;j++){
        if(arr[j]<=arr[r]){
            i++;  //inceremnt the second pointer by one and tha will become the next largest element
            swap(arr[i],arr[j]);    // that element gets echn
        } 
    }
swap(arr[i+1],arr[r]); 
return (i+1);
}

void QUICK_SORT(int arr[],int p, int r){
    if(p<r)
    {
        int q= PARTITION(arr,p,r);   // where to place the pivot element
        QUICK_SORT(arr,p,q-1);
        QUICK_SORT(arr,q+1,r);
    }
}

int main(){
	stringstream
    int n=5;
   // cout<<"Number of inputs"<<endl;
   // cin>>n;
    int arr[n];			//it will be stored as an array of numbers
    ofstream outfile ;   //outfile is the alias name
    
    string s;
    ifstream infile("random.txt");
    int i=0;
    if(infile.is_open())
    {
        while(getline(infile,s))	//it will get all nos into the file in the form of strings
        {
            int number = stoi(s);	//string to int conversion
            arr[i] = number; 
			i++;
        }
        infile.close();
    }
    else
    {
        cout<<"File couldn't be opened and read"<<endl;
    }
    QUICK_SORT(arr,0,n-1);
    
    ofstream outfile2 ;
    outfile.open("Sorted_random_array.txt");
    if(outfile.is_open())
    {
        for(int i = 0; i < n; i++)
            outfile<<arr[i]<<endl ; 
        
        outfile.close();
    }
    
    for(int i = 0; i < n; i++)
            cout<<arr[i]<<endl ; 
/*
    int arr[6]={7,5,9,3,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);   //standard to find the size of the array
    cout<<"Sorted array is: "<<endl;
    QUICK_SORT(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<",";  //display the elements
    }
    */
    return 0;
}
