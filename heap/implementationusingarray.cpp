#include<iostream>
#include<Math.h>
using namespace std;
class MinHeap{
      public:
      int *harr;
      int capacity;
      int heap_size;
      MinHeap(int cap){
            heap_size=0;
            capacity=cap;
          harr=new int[cap];
      }
  void linearSearch(int val){
        for(int i=0;i<heap_size;i++){
              if(harr[i]==val){
                    cout<<"Value Found!";
                    return;
              }
        }
        cout<<"Value Not Found";
  }
  void printArray(){
        for(int i=0;i<heap_size;i++){
              cout<<harr[i]<<" ";
        }
        cout<<endl;
  }
  int height(){
        return ceil(log2(heap_size)+1)-1;
  }

};
int main(){
      int s;
      cout<<"Enter the size of Min Heap"<<endl;
      cin>>s;
      MinHeap obj(s);
      cout<<"Min HEap Created"<<endl;

      int option,val;
      do{
            cout<<"What operation do you want to perform?"<<"Select Option number. Enter 0 to exit"<<endl;
            cout<<"1. Insert key/node/value"<<endl;
            cout<<"2. Delete key/node/value"<<endl;
            cout<<"3. Search key/node/value"<<endl;
            cout<<"4. Get Min"<<endl;
            cout<<"5. Extract Min"<<endl;
             cout<<"6. Height of heap"<<endl;
             cout<<"7. print heap values"<<endl;
              cout<<"8. Clear Screen"<<endl;
               cout<<"9. Exit program"<<endl;
               cin>>option;
          switch (option)
          {
          case 0:
                break;
          case 1:
             cout<<"Insertion Operation-"<<endl;
             cout<<"Enter the value to Search in heap";
             cin>>val;

             cout<<endl;
             break;
            case 3:
             cout<<"Insertion Operation-"<<endl;
             cout<<"Enter the value to Search in heap";
             cin>>val;
                
          default:
                break;
          }

      }while(option!=0);
}