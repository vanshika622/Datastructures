#include<iostream>
#define SPACE 10;
using namespace std;
class TreeNode{
		public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(){
		data=0;
		left=NULL;
		right=NULL;
		
	}
	TreeNode(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
class BST{
		public:
	TreeNode* root;
      BST(){
      	root==NULL;
	  }
	  bool isTreeEmpty(){
	  	if(root==NULL){
	  		return true;
		  }
		  else{
		  	return false;
		  }
	  }
	  void insert(TreeNode* new_node){
	  	if(root==NULL){
	  		root=new_node;
	  		cout<<"value is inserted"<<endl;
	  		return;
		  }
		  else{
		  	TreeNode* temp=root;
		  	while(temp!=NULL){
		  		if(temp->data==new_node->data){
		  		cout<<"value already inserted"<<endl;
		  		return;
			  }
			  else if(new_node->data<temp->data &&(temp->left==NULL)){
			  	temp->left=new_node;
			  	break;
			  }
			  else if(new_node->data<temp->data){
			  	temp=temp->left;
			  	
			  }
			  else if(new_node->data>temp->data &&(temp->right==NULL)){
			  	temp->right=new_node;
			  }
			  else if(new_node->data>temp->data){
			  	temp=temp->right;
			  	break;
			  }
			  }
		  	
		  }
	  }
	  void print2D(TreeNode * r, int space) {
      if(r==NULL){
      	return;
	  }
	  space+=SPACE;
	  print2D(r->right, space);
	  cout<<endl;
	  for(int i=0;i<space ;i++){
	  	cout<<" ";
	  }
	  cout<<r->data<<"\n";
	  print2D(r->left,space);
  }

		
};
int main(){
	TreeNode* new_node=new TreeNode();
	BST obj;
	int op, val;
	do{
		cout<<"Press 1 .Insert"<<endl;
		cout<<"Press 2. Delete"<<endl;
		cout<<"Press 3. Search"<<endl;
		cout<<"Press 4. Print /Traversal"<<endl;
		cout<<"Press 5. Height"<<endl;
		cout<<"Press 0. Exit Program"<<endl;
			cin>>op;
	switch(op){
		case 0:
			break;
		case 1:
		  cout<<"Enter the value to be inserted"<<endl;
		  cin>>val;
		  new_node->data=val;
		  obj.insert(new_node);
		  break;
		case 4:
		   obj.print2D(obj.root, 5);
		   break;
		   default:
		   cout<<"choose the correct option"<<endl;	
	}
	}while(op!=0);

	return 0;
}
