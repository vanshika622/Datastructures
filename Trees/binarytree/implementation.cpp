#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){

    
    node* root= new node(2);
    root->left=new node(3);
    root->right=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(6);
    root->right->left=new node(7);
    root->right->right=new node(8);
    inorder(root);

}