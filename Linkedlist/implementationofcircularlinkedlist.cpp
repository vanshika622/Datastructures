// circular singly linked list one node point to itself 
// in this we keep the pointer at last not ar start to avoid traversing
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(){
			data=0;
			next=NULL;
		}
};
node* singlecircularnode(int data){
	node* n=new node();
	 n->data=data;
	  n->next=n;
	  
	  return n;
}
node* AddtoBegining(node* tail,int data){
	node* n= new node();
	n->data= data;
	
	//code
	n->next=tail->next;
	tail->next=n;
	
	return tail;
	
	
}
node* AddtoEnd(node* tail,int data){
	node* n =new node();
	n->data=data;
	
	 node* temp=tail->next;
	 tail->next=n;
	 n->next=temp;
	 tail=tail->next;
	 return tail;
}
node* insertioninBetween(node* tail, int pos, int data){
	node* newnode= new node();
	newnode->data=data;
	node* temp=tail->next;
	 pos--;
	 while(pos!=1){
	 	temp=temp->next;
	 	pos--;
	 }
	 newnode->next=temp->next;
	 temp->next=newnode;
	 
	 return tail;
}
node* deleteAtBegin(node* tail){
	node* temp=tail->next;
	tail->next=temp->next;
	temp->next=NULL;
	delete(temp);
	
	return tail;
}
node* deleteAtEnd(node* tail){
	if(tail==NULL){
		return tail;
	}
	node* temp=tail->next;
	if(tail->next==tail){
		delete(tail);
		tail=NULL;
		return tail;
	}
//	node* deletednode;
	
	while(temp->next!=tail){
			temp=temp->next;
	}
//	deletednode=tail;
	temp->next=tail->next;
	delete(tail);
	tail=temp;
//	delete(deletednode);
	return tail;
}
node* deleteInBetween(node* tail, int pos){
	if(pos==1){
	 tail=deleteAtBegin(tail);
	 return tail;
	}
	if(tail==NULL){
		return tail;
	}
	
	node* temp=tail->next;
	if(tail->next==tail){
		delete(tail);
		tail=NULL;
		return tail;
	}
	node*temp2;
	pos--;
	while(pos!=1){
		temp=temp->next;
		pos--;
	}
	temp2=temp->next;
	temp->next=temp2->next;
	//handling tha case of deleting last node
	if(temp2==tail){
		tail = temp;
	}
	delete(temp2);
	return tail;
	
}
int searchAnElement(struct node* tail, int element){
	node* temp;
	int index=1;
	if(tail==NULL){
		return -2;
	}
	temp=tail->next;
	do{
		if(temp->data==element)
		  return index;
		  temp=temp->next;
		  index++;
	} while(temp!=tail->next);
	return -1;
}
void print(node* tail){
	node* temp=tail->next;
	int count=0;
	do{
		cout<<temp->data<<" ";
		count++;
		temp=temp->next;
	}while(temp!=tail->next);
	cout<<"Number of elements :"<<count<<endl;
	cout<<endl;
}

int main(){
	node* tail= new node();
	tail=singlecircularnode(45);
	tail= AddtoBegining(tail, 35);
	tail = AddtoEnd(tail, 55);
	tail= AddtoEnd(tail, 65);
	print(tail);
	
	tail=insertioninBetween(tail, 3,75);
	print(tail);
	tail=deleteAtBegin(tail);
	print(tail);
//	tail=deleteAtEnd(tail);
//   tail =deleteInBetween(tail,3);
//
//	print(tail);
cout<<"element to be searched fount at index : "<<searchAnElement(tail,55)<<endl;;
print(tail);
	return 0;
	
}
