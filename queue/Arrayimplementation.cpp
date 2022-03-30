#include<iostream>
using namespace std;
#define n 100
class queue{
    int *arr;
    int front;
    int back;
    public:
      queue(){
       arr=new int[n];
       front=-1;
       back=-1;

      }
      bool isEmpty(){
         if(front==-1 || back==-1){
             return true;
            }
            return false;
     }
     bool isFull(){
     	if(back==n-1){
     		return true;
		 }else{
		 	return false;
		 }
	 }
      void enqueue(int x){
          if(back==n-1){
              cout<<"Queue oveflow"<<endl;
              return;
          }
          else if(isEmpty()){
          	back=0;
          	front =0;
          	arr[back]=x;
		  }else{
		  	back++;
		  	arr[back]=x;
		  }
      }
      void dequeue(){
          if(isEmpty()){
              cout<<"No elements in queue"<<endl;
              return;
          }
          else if(front==back){
          	 front=-1;
          	 back=-1;
		  }
		  else{
		  	front++;
		  }
		  
          
      }
      int peek(){
            if(front==-1 || back==-1){
              cout<<"No elements in queue"<<endl;
              return -1;
            }
             return arr[front];
      }
     
};
int main(){
     queue q;
     q.enqueue(1);
      q.enqueue(2);
       q.enqueue(3);
        q.enqueue(4);
         q.enqueue(5);
          q.enqueue(6);

       cout<<q.peek()<<endl;
       q.dequeue();  
        cout<<q.peek()<<endl;
       q.dequeue(); 
        cout<<q.peek()<<endl;
       q.dequeue();
        cout<<q.peek()<<endl;
       q.dequeue();
       return 0;
}
