#include<iostream>
using namespace std;
class node{
	public:
	node* prev;
	int data;
	node* next;
	node(int val){
		prev=NULL;
		data=val;
		next=NULL;
	}
};
node* addToEmpty(node* head,int data){
	node* n= new node(data);
	head=n;
	delete(n);
	return head;
	
}
node* insertAtBegin(node* head, int data){
	node* n=new node(data);
	n->next=head;
	head->prev=n;
	head=n;
     return head;	

}
node* insertAtEnd(node* head, int data){
	node* n =new node(data);
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
	n->next=NULL;
	return head;
}
node* insertInBetween(node* head,int data, int pos){
	if(pos==1){
		insertAtBegin(head,data);
		return head;
	}
	else{
		node* n=new node(data);
		node* temp=head;
		node* temp2=NULL;
		pos--;
		while(pos!=1){
			temp=temp->next;
			pos--;
		}
		temp2=temp->next;
		
		//code for making links
		n->next=temp->next;
		temp2->prev=n;
		temp->next=n;
		n->prev=temp;
		
	}
	return head;
}
node* deleteAtBegin(node* head){
	node* temp=head;
    head=head->next;
	head->prev=NULL;
	delete(temp);
	return head;
}
node* deleteAtEnd(node* head){
	node* temp=head;
	node* temp2;
	node* lastnode;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
//	temp2=temp->prev;
// temp2->next=NULL;
//delete(temp);
//OR
  lastnode=temp->next;
	 temp->next=NULL;
	//not mandatory
//	lastnode->prev=NULL;
	 delete(lastnode);
	return head;
}
node* deleteInBetween(node* head, int pos){
	if(pos==1){
	 node* temp=deleteAtBegin(head);
		return temp;
	}
	else if(head==NULL){
		cout<<"List is empty"<<endl;
		return NULL;
	}
	else{
		node* temp=head;
		node* temp2;
		pos--;
		while(pos!=1){
		 temp=temp->next;
		 pos--;	
		}
		temp2=temp->next;
		temp->next=temp2->next;
		temp2->next->prev=temp;
		return head;
	}
}
node* reversetheList(node* head){
	node* ptr1=head;
	node* ptr2=ptr1->next;
	
	ptr1->next=NULL;
	ptr1->prev=ptr2;
	
	while(ptr2!=NULL){
		ptr2->prev=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->prev;
	}
	head=ptr1;
	return head;
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
		
	}
	cout<<endl;
}
int main(){
	node* head= new node(55);
	head=insertAtBegin(head, 45);
	head= insertAtEnd(head, 65);
		head= insertAtEnd(head, 85);	
		head= insertAtEnd(head, 95);
	display(head);
	head=insertInBetween(head, 75, 4);
	display(head);
	head=deleteAtBegin(head);
	display(head);
//	head= deleteAtEnd(head);
//	display(head);
	head=deleteInBetween(head, 3);
	display(head);
	head= reversetheList(head);
	display(head);
}
