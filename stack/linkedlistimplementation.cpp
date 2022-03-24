// malloc() returns null ten this means stack is full or heap memory no longer availaibele
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node* link;
}*top =NULL;
void push(int data){
    struct node* newNode;
    newNode=(node*) malloc(sizeof(newNode));
    if(newNode==NULL){
        cout<<"Stack Over flow";
        exit(1);
    }
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=top;
    top=newNode;

}
void pop(){
	if(top==NULL){
		cout<<"Stack is Empty\n";
		return;
	}
	struct node* temp=top;
	top=top->link;
	temp->link=NULL;
	delete(temp);
	cout<<"Element is deleted\n";
	
}
int isEmpty(){
	if(top==NULL){
		return 1;
	}
	else 
	return 0;
}
int peek(){
	if(top==NULL){
		cout<<"Stack is Empty\n";
		return 0;
	}
	return top->data;
}
void printReverse(node* head)
{
    // Base case
    if (head == NULL)
    return;
 
    // print the list after head node
    printReverse(head->link);
 
    // After everything else is printed, print head
    cout << head->data << " ";
    
}
void print(){
    struct node* temp;
    temp=top;
    if(temp==NULL){
    	cout<<"Stack is Empty\n";
	}
    cout<<"The stack elements are:";
     printReverse(temp);
  
}
int main(){
    int choice, data;
    while(1){
       cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Print\n";
        cout<<"4. isEmpty\n";
        cout<<"5. peek Element\n";
         cout<<"6. Quit\n";
          cout<<"Enter Your choice:";
          cin>>choice;

          switch(choice){
              case 1:
               cout<<"Enter the elemnent to be pushed: ";
               cin>>data;
               push(data);
               break;
               case 2:
               	pop();
               	
               	break;
               case 3:
               print();
               cout<<"\n";
                 break;
                 case 4:
               if(isEmpty()){
               	cout<<"stack is Empty\n";
			   }
			   else{
			   	cout<<"Stack is not empty\n";
			   }
               
                 break;
                 case 5:
               cout<<peek()<<"\n";
              
                 break;
                 case 6: exit(1);
                 default:
                 cout<<"wrong choice";
                 break;
          }


    }
    return 0;
}
