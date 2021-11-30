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
void insertAtTail(Node* &head, int data){
    Node* n= new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}
void insertAthead(Node* &head, int data){
    Node* newnode= new Node(data);
       newnode->next=head;
       head=newnode;
}

void insertbetween(Node* &head, int pos, int data){
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
Node* deletinghead(Node* &head){
    if(head==NULL){
        cout<<"List is already Empty"<<endl;
        return head;
    }
    Node* temp=head;
    head=head->next;
      delete(temp);
      return head;
                       
}
Node* deletingTail(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
    Node* temp=head;
    Node* temp2=head;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    }
    return head;
}
Node* deletingAtparticularpos(Node* &head,int pos){
       Node* current=head;
       Node* previous=head;
       if(head==NULL){
           cout<<"List is empty"<<endl;

       }
       else if(pos==1){
           head=current->next;
           free(current);
           current=NULL;
       }
       else{
           while(pos!=1){
               previous=current;
               current=current->next;
               pos--;
           }
           previous->next=current->next;
           free(current);
           current=NULL;
       }
       return head;
}
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
Node* reverseByIteration(Node* &head){
   Node* curr =head;
   Node* prev=NULL;
   while(curr!=NULL){
       Node* temp=curr->next;
       curr->next=prev;
       prev=curr;
       curr=temp;
   } 
   return prev;
    
}
Node* reverseByrecursively(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newHead= reverseByrecursively(head->next);
      Node* headNext=head->next;
      headNext->next=head;
      head->next=NULL;
      return newHead;

}
Node* middle(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
bool palindrome(Node* &head){
    if(head==NULL)
      return true;

    Node* mid=middle(head); 
    Node* last = reverseByIteration(mid->next);
    Node* curr=head;
    while(last!=NULL){
        if(last->data!=curr->data)
           return false;

         last=last->next;
         curr=curr->next;  
    } 
    return true;

}
int main(){
    Node* head= NULL;
    insertAtTail(head, 10);
    insertAtTail(head,20);
    insertAthead(head,5);
    insertAtTail(head,30);
    insertbetween(head,3,50);
    // display(head);

   cout<<palindrome(head)<<endl;
 
   
    



    return 0;
}
