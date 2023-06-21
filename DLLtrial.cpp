#include <iostream>
using namespace std;

struct datanode{
	int data;
	datanode *back;
	datanode *fore;
	
};

struct headnode{
	int count;
	datanode *last;
	datanode *first;
};

class DLL{
	private:
		headnode *dllhead;
		datanode *pPre;
		datanode *pLoc;
		
	public:
		DLL(){
			dllhead= new headnode;
			
			dllhead->first=NULL;
			dllhead->last=NULL;
			dllhead->count=0;
		}
		
		bool InsertNode(int dataIn){
			datanode *pNew = new datanode;
			pNew->data=dataIn;
			pNew->back = pNew->fore= NULL;
			
			if (pPre==NULL)
				{
					
					pNew->back=NULL;
					dllhead->first=pNew;
				}
			else
				{
					pNew->back=pPre;
					pPre->fore=pNew;
				}
				
			if(pLoc==NULL)
				{
					pNew->fore=NULL;
					dllhead->last=pNew;
				}
			else
				{
					pNew->fore=pLoc;
					pLoc->back=pNew;
				}
				dllhead->count++;
		}
		
		bool deleteNode(int &dataOut){
				if(pLoc->back!=NULL)
					pLoc->back->fore=pLoc->fore;
				else
					dllhead->first=pLoc->fore;
				
				if(pLoc->fore!=NULL)
					pLoc->fore->back=pLoc->back;
				else
					dllhead->last=pLoc->back;
					
				dllhead->count--;
				dataOut=pLoc->data;
				delete pLoc;
				return true;
		}
		
		bool SearchDLL(int &target ){
			datanode *pNew= new datanode;
			pNew=dllhead->first;
			while(pNew!=NULL && target!=pNew->data)
			{
				pNew=pNew->fore;
			}
			if(pNew==NULL)
				{
					cout<<"element not found";
					return false;
					}
			else
				{
					cout<<"element found"<<endl;
					return true;
					}	
		}
		
		bool emptyDLL(){
			if (dllhead->count==0)
				return true;
			else
				return false;
		}
		
		int DLLCount(){
			return dllhead->count;
		}
		
		bool fTraverseDLL(){		//forward traversal
			datanode *pWalker = new datanode;
			pWalker = dllhead->first;
			while(pWalker!=NULL){
				return pWalker->data;
				pWalker= pWalker->fore;
			}
			return true;
		}
		
		bool rTraversalDLL(){			//reverse traversal
			datanode *pWalker = new datanode;
			pWalker = dllhead->last;
			while(pWalker!=NULL)
			{
				return pWalker->data;
				pWalker= pWalker->back;
			}
			return true;
		}    
		
		bool DestroyDLL(){
			datanode *pWalker = new datanode;
			pWalker=dllhead->first;
			while(pWalker!=NULL)
			{
				dllhead->first=pWalker->fore;
				delete pWalker;
				dllhead->count--;
				pWalker=dllhead->first;
			}
			delete dllhead;
			return true;
		}   
		
		bool SearchfromFront(int &target){
			datanode *pLoc= new datanode;
			pLoc= dllhead->first;
			int pos=1;
			while (pLoc!=NULL && target >pLoc->data)
			{	pos++;
				pLoc=pLoc->fore;		
			}
			
			if(pLoc==NULL)
				return -1;
			else if (target==pLoc->data)
				return pos;
			else
				return -1;
			
		}     
		
		bool SearchfromRear(int &target) {
			datanode *pLoc= new datanode;
			pLoc=dllhead->last;
			int pos=1;
			while(pLoc!=NULL && target <pLoc->data){
				pos++;
				pLoc=pLoc->back;
			}
			if (pLoc==NULL)
				return -1;
			else if (target==pLoc->data)
				return pos;
			else
				return -1;
		}
		bool removeNode(int &dataOut){
			bool found;
			bool success;
			int dltkey;
			found= SearchDLL(dataOut);
			if (found)
				{
					cout<<"Element found!";
					success=deleteNode(dataOut);
					success= true;
				}
			else
			{
				cout<<"element not found";
				success=false;			
			}
			found = SearchDLL(dltkey);
			if (!found){
				cout<<"element not found. Can't delete";
				success=true;				
			}				
			else 
				success= deleteNode(dltkey);
				
			return success;	
		}
		
		bool addNode(int dataIn){
			bool found;
			bool success;
			found=SearchDLL(dataIn);
			if(found)
				{
					cout<<"Duplicate element. Can't insert";
					success=false;
				}
			else
				success=InsertNode(dataIn);
			
			return success;
		}                                                              
};

int main(){
	DLL d;
	bool res,found,success;
	int op,count,dataIn,n;
	

	
	do{
		cout<<"1.Insert node	2.Delete Node	3.SearchDLL		4.EmptyDLL	5.fTraverseDLL"<<endl;
		cout<<"6.rTraverseDLL	7.DestroyDLL	8.SearchFromFront	9.SearchFromRear	10.AddNode	11.RemoveNode"<<endl;
		cout<<"enter option:"<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"enter data to be inserted: "<<endl;
				cin>>n;
				found= d.SearchDLL(n);
				if (found)
				{
					cout<<"Duplicate element found!!"<<endl;
					cout<<"Cannot be inserted"<<endl;				
				}
				else
				{
					success=d.InsertNode(n);
					cout<<"Element is inserted successfully"<<endl;
				}
				break;
				
			case 2:
				cout<<"enter element to be deleted: "<<endl;
				cin>>n;
				found=d.SearchDLL(n);
				if(found)
				{
					success=d.deleteNode(n);
					cout<<"Element is deleted successfully"<<endl;
					cout<<"Deleted element is:"<<n<<endl;
				}
				else
					{
						success=false;
					cout<<"element does not exist"<<endl;
					}
				break;
				
			case 3:
				cout<<"enter element to be searched"<<endl;
				cin>>n;
				found=d.SearchDLL(n);
				if (found){
					cout<<"Search element is found"<<endl;
				}
				else{
					cout<<"Search element is not found"<<endl;	
					}
				break;
				
			case 4:
				res=d.emptyDLL();
				if(res)
					cout<<"the DLL is empty"<<endl;
				else
					cout<<"DLL is not empty"<<endl;
				break;
			
			case 5:
				res=d.fTraverseDLL();
				break;
				
			case 6:
				res=d.rTraversalDLL();
				break;
				
			case 7:
				res=d.DestroyDLL();
				cout<<"DLL has been successfully destroyed"<<endl;
				break;
				
			case 8:
				cout<<"enter element to be searched: "<<endl;
				cin>>n;
				found=d.SearchfromFront(n);
				if(found)
					cout<<"element has been found"<<n<<endl;
				else
					cout<<"element not found"<<endl;
				break;
				
			case 9:
				cout<<"enter element to be searched: "<<endl;
				cin>>n;	
				found=d.SearchfromRear(n);
				if(found)
					cout<<"element has been found"<<n<<endl;
				else
					cout<<"element not found"<<endl;
				break;
				
			case 10:
				cout<<"enter the element to be added"<<endl;
				cin>>n;
				res=d.addNode(n);
				if(res)
					cout<<"element has been successfully added"<<endl;
				else
					cout<<"element could not be added"<<endl;
				break;
			
			case 11:
				cout<<"enter the node to be removed"<<endl;
				cin>>n;
				found=d.SearchDLL(n);
				if(found)
				{
					success=d.removeNode(n);
					cout<<"element has been successfully removed!"<<endl;
				}
				else
					cout<<"element not found and cannot be removed"<<endl;
				break;	
				
		}
		
	}while(op<=10);
}

