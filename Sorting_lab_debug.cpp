#include <iostream>
#include <fstream>
#include <limits.h>
#include <cstring>
using namespace std;

class Sort{
    long int A[10010];
    public:
    void readInput(int n,int type){
    char s[16]; 
    switch(type){
    case 0: strcpy(s,"input.txt"); break;
    case 1: strcpy(s,"input-asc.txt"); break;
    case 2: strcpy(s,"input-desc.txt"); break;
}
        ifstream fin(s);
        for(int i=0;i<n;i++){
            fin>>A[i];
        }
        cout<<A[0]<<" "<<A[1];
        fin.close();
    }
    void writeOutput(int n){
        ofstream fout("output.txt");
        for(int i=0;i<n;i++)
            fout<<A[i]<<'\n';
        fout.close();
    }
    int insertionSort(int n){  
        int count=0;
        int key,j;
        for(int i=1;i<n;i++){
            key=A[i];
            j=i-1;
            count++;
            while(j >= 0 && A[j]>key)   
            {
                A[j+1]=A[j];
                j=j-1;
                count++;
            }
            A[j+1]=key;
        }
        return count;
    }

    void mergeSort(int p,int r,int &count){
        if(p < r)
        {
            int q=(p + r) / 2;
            mergeSort(p, q, count);
            mergeSort(q+1, r, count);
            merge(p, q, r, count);
        }
    }

    void merge(int p,int q,int r, int &count){
        int i, j;
		int n1=q - p + 1;
        int n2=r - q;
        int L[n1+2],R[n2+2];
        for(int i=0; i < n1; i++){
            L[i]=A[p+i];
        }
        L[n1] = INT_MAX;
        for(int j=0;j<n2;j++){
            R[j]=A[q+j+1];
        }
        R[n2]=INT_MAX;
        i = 0;
		j = 0;
        for(int k=p; k<=r; k++){
            count++;
            if(L[i] <= R[j]){
                A[k]=L[i];
                i++;
            }
            else{
                A[k]=R[j];
                j++;
            }
        }
    }
    int Partition(int p, int r, int &count){
		int i,key,j,n,t;
		key = A[r];
		i = p-1;
		for(j = p; j<=r-1; j++){
			count++;
			if(A[j]<=key){
				i++;
			swap(A[i],A[j]);
		}
}
	count++;
	swap(A[i+1],A[j]);
	return i+1;
	}
	void quickSort(int p,int r,int &count){
	int q;
	if(p<r){
		q=Partition(p, r, count);
		quickSort(p, q-1, count);
		quickSort(q+1, r,count);
		}
	}
void maxHeapify(int heapsize,int i, int &count){
	int left, right, largest;
	left = 2*i + 1;
	right = 2*i + 2;
	count++;
if(left <= heapsize && A[left]>A[i]){
	largest = left;
	}
	else{
		largest = i;
	}
if(right <= heapsize && A[right]> A[i]){
largest = right;
}
if(i != largest){
swap(A[i],A[largest]);
maxHeapify(heapsize, largest, count);
}
}
void buildMaxHeap(int heapsize, int &count){
for(int i = (heapsize+1)/2;i>=0;i--){
maxHeapify(heapsize, i, count);
}
}
int heapsort(int n){
int count = 0;
int heapsize = n-1;
buildMaxHeap(heapsize, count);
for(int i=n-1;i >= 1;i--){
swap(A[0],A[i]);
heapsize--;
maxHeapify(heapsize, 0, count);
}
return count;
}
};

int main()
{
    Sort s;
    int n,choice,count;
    int len[7]={10, 50, 100, 500, 1000, 5000, 10000};
    do{
cout<<"Choose Sorting Technique ... "<<endl;
    cout<<"1.Insertion Sort, 2.Merge Sort, 3.Heap Sort, 4.Quick Sort";
    cout<<"Enter Your Choice: ";
    cin>>choice;
    if(choice >= 5)
    break;
    cout<<"For Random Input: "<<endl;
    for(int i=0; i<7; i++){
    count = 0;
    n=len[i];
    s.readInput(n,0);
    switch(choice){
           case 1:
               count = s.insertionSort(n);
               break;
               
           case 2:
               s.mergeSort(0,n-1,count);
               break;
           
           case 3:
            count = s.heapsort(n-1);
            break;
           
           case 4:
            s.quickSort(0, n-1, count);
            break;
       }
        s.writeOutput(n);
        cout<<"InputSize : "<<n<<"\t"<<"No.of Comparision : "<<count<<endl;
}
cout<<"For Ascending Input: "<<endl;
    for(int i=0; i<7; i++){
    count = 0;
    n=len[i];
    s.readInput(n,1);
    switch(choice){
           case 1:
               count = s.insertionSort(n);
               break;
               
           case 2:
               s.mergeSort(0,n-1,count);
               break;
           
           case 3:
            count = s.heapsort(n-1);
            break;
           
           case 4:
            s.quickSort(0, n-1, count);
            break;
       }
//         s.writeOutput(n);
        cout<<"InputSize : "<<n<<"\t"<<"No.of Comparision : "<<count<<endl;
}
        cout<<"For Descending Input: "<<endl;
    for(int i=0; i<7; i++){
    count = 0;
    n=len[i];
    s.readInput(n,2);
    switch(choice){
           case 1:
               count = s.insertionSort(n);
               break;
               
           case 2:
               s.mergeSort(0,n-1,count);
               break;
           
           case 3:
            count=s.heapsort(n-1);
            break;
           
           case 4:
            s.quickSort(0, n-1, count);
            break;
       }
//         s.writeOutput(n);
        cout<<"InputSize : "<<n<<"\t"<<"No.of Comparision : "<<count<<endl;
}
    }
    while(choice < 5);
    return 0;
}
