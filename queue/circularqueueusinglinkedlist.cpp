#include<iostream>
using namespace std;
class node{
	public:
		int key;
		int data;
		node* next;
		node(int k, int d){
			key=k;
			data=d;
			next=NULL;
		}
};
class Queue{
	public:
		node* front;
		node* rear;
		Queue(){
			front=NULL;
			rear=NULL;
		}
		bool isEmpty(){
			if(front==NULL && rear==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		bool ckeckIfNodeExist(node* n){
			node* temp=front;
			bool exist=false;
		 do	{
				if(temp->key==n->key){
					exist=true;
					break;
				}
				temp=temp->next;
			}while(temp!=front;
			return exist;
		}
		void enqueue(node* n){
			if(isEmpty()){
				front=n;
				rear=n;
				cout<<"Node enqueued succeed"<<endl;
			}
			else if(ckeckIfNodeExist(n)){
				cout<<"Node alreay exist with this value"<<endl;
			}
			else{
				rear->next=n;
				rear=n;
				n->next=front;
			}
		}
		node* dequeue(){
			node* temp=NULL;
			if(isEmpty()){
				cout<<"Stack underflow"<<endl;
				return NULL;
			}
			else{
				if(front==rear){
					temp=front;
					front=NULL;
					rear=NULL;
					return temp;
				}
				else{
					temp=front;
					front=front->next;
					rear->next=front;
					return temp;
				}
			}
		}
		int count(){
			int count=0;
			node* temp=front;
			do{
				count++;
				temp=temp->next;
			}while(temp!=front);
			return count;
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is Empty"<<endl;
			}
			else{
				cout<<"All values in the Queue are :"<<endl;
				node* temp=front;
				while(temp!=NULL){
					cout<<temp->key<<" ---"<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<temp->key<<" ---"<<temp->data<<" ";
				cout<<endl;
			}
		}
};

int main(){
	node* newnode=new node(1,45);
	Queue q;
	q.enqueue(newnode);
	node* newnode2=new node(2,55);
		q.enqueue(newnode2);
		node* newnode3=new node(3,65);
		q.enqueue(newnode3);
		q.display();
		newnode=q.dequeue();
		cout<<newnode->key<<"---"<<newnode->data<<endl;
		q.display();
}
