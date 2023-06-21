#include <iostream>
using namespace std;

class Stack{
	private:
		int arr[5];
		int top;
	public:
		Stack(){                //constructor
			top=-1;
			for(int i=0; i<5; i++){
				arr[i]=0;
			}
		}
		
		bool isEmpty(){
			if (top==-1)
				return true;
			else
				return false;
		}
		
		bool isFull(){
			if (top==4)
				return true;
			else
				return false;
			}
			
		void Push(int val){
			if (isFull())
				cout<<"Stack Overflow!"<<endl;
			else
				top++;
				arr[top]=val;
		}
		
		int Pop(){
			if (isEmpty()){
				cout<<"Stack underflow!"<<endl;
				return 0;
				}
			else
				{int popValue=arr[top];
				arr[top]=0;
				top--;
				return popValue;} 
		}
		
//		int Count(){
//			return top+1;
//		}
		
//		int Peek(int pos){
//			if(isEmpty())
//				cout<<"Stack undeflow!"<<endl;
//			else
//				return arr[pos];
//		}
		
		void Display(){
			cout<<"All the elements of the stack are: "<<endl;
			for(int i=4;i>=0;i--){  //traversing backwards in the stack
				cout<< arr[i]<<endl;
			}
		}
};
int main(){
	Stack s1;
	int option,position,value;
	
	do{
		cout<<"Choose an option: (enter 0 to exit)"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Is Empty"<<endl;
		cout<<"4. Is Full"<<endl;
		//cout<<"5. Count"<<endl;
		//cout<<"6. Peek"<<endl;
		cout<<"5. Display"<<endl;
		
		cin>>option;
		switch(option){
			case 1:
				cout<<"enter an item to push in stack: "<<endl;
				cin>>value;
				s1.Push(value);
				break;
				
			case 2:
				cout<<"Pop called"<<endl;
				s1.Pop();
				break;
				
			case 3:
				if (s1.isEmpty())
				cout<<"Stack is empty"<<endl;
				else
				cout<<"Stack is not empty"<<endl;
				break;
				
			case 4:
				if (s1.isFull())
				cout<<"Stack is full"<<endl;
				else
				cout<<"stack is not full"<<endl;
				break;
				
			case 5:
				cout<<"the stack is:"<<endl;
				s1.Display();
				break;
				
			default:
				if (option>5)
				cout<<"choose an appropriate option"<<endl;
				else
				continue;
		}
	}
	
	while(option!=0);{
		cout<<"correct option"<<endl;
		}
return 0;	
}
