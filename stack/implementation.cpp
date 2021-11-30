#include<iostream>
using namespace std;
#define n 1000
class MyStack{
    int *arr;
    int top;
    
    public:
    MyStack(){
        arr=new int[n];
        top==-1;
    }
   
   void push(int x){
       if(top==n-1){
           cout<<"Stack overflow"<<endl;
           return;
       }
       top++;
       arr[top]=x;

   }
   void pop(){
       if(top==-1){
           cout<<"No Element to pop"<<endl;
           return;
       }
       top--;
   }
   int Top(){
       if(top==-1){
           cout<<"No Element in stack"<<endl;
           return -1;
       }
       return arr[top];
   }
   bool empty(){
       return top==-1;
   }
};
int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    // st.pop();
    // cout<<st.Top()<<endl;
    // st.pop();
    // st.pop();
    // cout<<st.empty();

}