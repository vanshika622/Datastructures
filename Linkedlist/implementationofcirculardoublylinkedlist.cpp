#include<iostream>
using namespace std;
class node{
	public:
		node* prev;
		int data;
		node* next;
		node(int data){
			prev=NULL;
			this.data=data;
			next=NULL;
			
		}
};
node* singlenodedoublycircular(node* head, int data){
	node* n=new node(data);
	n->prev=n;
	n->next=n;
	
	return n;
}
int main(){
	
}
