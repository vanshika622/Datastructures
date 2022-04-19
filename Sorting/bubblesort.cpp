#include<iostream>
using namespace std;
void Bubblesort(int arr[],int n){
	for(int i=0;i<n-1;i++){                //--for rounds
	   int flag=0;
		for(int j=0;j<n-i-1;j++){           //--for comparing and swappint
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
Bubblesort(arr,n);
}
