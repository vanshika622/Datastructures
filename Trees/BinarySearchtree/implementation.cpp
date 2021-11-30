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
node* CreateBst(node* root, int val){
    if(root==NULL)
     return NULL;
      if (val<root->data)
      {
          root->left=CreateBst(root->left, val);
      }
      else{
          root->right=CreateBst(root->right,val);
      }
      return root;
      
}
void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=NULL;
   root=  CreateBst(root,5);
         CreateBst(root,1);
         CreateBst(root,3);
         CreateBst(root,4);
         CreateBst(root,7);
        inorder(root);


}