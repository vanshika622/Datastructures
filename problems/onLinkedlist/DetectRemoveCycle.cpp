#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(Node* head, int data){
    Node* newNode= new Node(data);
    if(head==NULL){
         head=newNode;
         return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
}
void insertBetween(Node* head, int data, int pos){
    Node* n=new Node(data);
    Node* temp=head;
    pos--;
    while(pos!=1){
        temp=temp->next;
        pos--;
    }
    n->next=temp->next;
    temp->next=n;
}
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void makeCycle(Node* &head, int pos){
   Node* temp=head;
   Node* startNode;
   int count=1;
   while(temp->next!=NULL){
       if(count==pos){
           startNode=temp;
       }
       temp=temp->next;
       count++;
   }
   temp->next=startNode;
}

int main(){
    Node*  head= NULL;
    insertAtTail(head, 10);
    insertAtTail(head,20);
   
    insertAtTail(head,30);
    insertBetween(head,3,50);
    

   
    
 insertAtTail(head, 60);
    insertAtTail(head,70);
    display(head);

    makeCycle(head,3);
    display(head);
}