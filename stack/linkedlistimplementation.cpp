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
void print(){
    struct node* temp;
    temp=top;
    cout<<"The stack elements are:";
    while(temp){
        cout<<temp->data;
        temp=temp->link;
    }
    cout<<"\n";
}
int main(){
    int choice, data;
    while(1){
       cout<<"1. Push\n";
        cout<<"2. Print\n";
         cout<<"3. Quit\n";
          cout<<"Enter Your choice:";
          cin>>choice;

          switch(choice){
              case 1:
               cout<<"Enter the elemnent to be pushed: ";
               cin>>data;
               push(data);
               break;
               case 2:
               print();
                 break;
                 case 3: exit(1);
                 default:
                 cout<<"wrong choice";
                 break;
          }


    }
    return 0;
}
