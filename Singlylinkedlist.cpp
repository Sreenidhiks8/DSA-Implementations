#include<iostream>
using namespace std;

struct datanode
{
		int data;
		datanode *link;
};

struct headnode
{
			int count;
			datanode *head;
};


class SinglyLinkedList
{
	  private: headnode *list;
	  public:
			SinglyLinkedList()
				{
						list=new headnode;
							list->head=NULL;
							list->count=0;
				}
				
				bool insertnode(datanode *pPre,int dataIn)
				{
							datanode *pNew=new datanode;
							pNew->data=dataIn;
							if(pPre==NULL)
							{
										pNew->link=list->head;
										list->head=pNew;
							}
							else
							{
								  pNew->link=pPre->link;
								  pPre->link=pNew;
							}
							list->count++;
							return true;
				}
				
				bool deletenode(datanode *pPre,datanode *pLoc,int &dataOut)
				{
						 dataOut= pLoc->data;
						 datanode *temp = pLoc;
						  if(pPre==NULL)
						  {
						  		list->head=pLoc->link;
	
								}
								else
								{
									pPre->link=pLoc->link;
								}
								delete(temp);
								list->count--;
								return true;
				}
				
				bool searchList(datanode *(&pPre),datanode *(&pLoc),int target)
				{
						//	datanode *pPre=new datanode;
					//		datanode *pLoc=new datanode;
							pPre=NULL;
							pLoc=list->head;
							
							while(pLoc!= NULL && target > pLoc->data)
							{
									pPre=pLoc;
									pLoc= pLoc->link;
							}
							if(pLoc==NULL)
							{
										return false;
							}
							else
							{
										if(target==pLoc->data)
										{
											  return true;
										}
										else
										{
											return false;
										}
							}
				}
				
				bool emptylist()
				{
						if(list->count==0)
						{
							  return true;
						}
						else
						{
							   return false;
						}
				}
				
				int listCount()
				{
						return list->count;
				}
				
				bool display()
				{
						if(emptylist())
						{
							return false;
						}
						else
						{
							  datanode *pWalker= new datanode;
							  pWalker=list->head;
							  
							  while(pWalker)
							  {
							  	  cout<<pWalker->data;
							  	  pWalker=pWalker->link;
									}
									return true;
						}
				}		
};

int main()
{
	   SinglyLinkedList s;
	   bool found;
	   bool success;
	   int n,num,count, dataIn;
	   datanode *Pre, *pLoc; 
	   
	   do
	   {
				
	   cout<<"Enter 1 to insert data, 2- to search element 3-to traverse and display 4 for list count and 5 to delete"<<endl;
	   cin>>num;
	   
	   switch(num)
	   {
			
	   case 1:
	   cout<<"Enter the data to be inserted"<<endl;
	   cin>>n;
	   found=s.searchList(Pre,pLoc,n);
	   
	   if(found)
	   {
	   	 cout<<"Duplicate element found"<<endl;
	   	 cout<<"Cannot be inserted"<<endl;
				}
				else
				{
					  success=s.insertnode(Pre,n);
					  cout<<"Element is inserted successfully"<<endl;
				}
				break;
				
				case 2:
					cout<<"Enter the element to be searched"<<endl;
					cin>>n;
					found=s.searchList(Pre,pLoc,n);
					if(found)
					{
						  cout<<"Search element is found"<<endl;
					}
					else
					{
						cout<<"Search element is not found"<<endl;
					}
					break;
					
					case 3:
						success=s.display();
						break;
						
					case 4:
						count=s.listCount();
						cout<<"The number of elements in the list is:"<<count<<endl;
						break;
					
					
					case 5:
						
						   cout<<"Enter the data to be deleted"<<endl;
						   cin>>n;
						   found=s.searchList(Pre,pLoc,n);
						   
						   if(found)
						   {
						   	   success=s.deletenode(Pre,pLoc,n);
										  cout<<"Element is deleted successfully"<<endl;
										  cout<<"Deleted element is:"<<n<<endl;
						   	 
									}
									else
									{
										  success=false;
									}
									break;
				}
			}
					while(num<=5);
}
