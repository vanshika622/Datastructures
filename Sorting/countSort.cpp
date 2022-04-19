#include<iostream>
using namespace std;
void countSort(int arr[], int n){
	int k=arr[0];
	for(int i=0;i<n;i++){
		k=max(k,arr[i]);
	}
	int countArr[10000];
	for(int i=0;i<n;i++){
		countArr[arr[i]]++;
	}
	for(int i=1;i<=k;i++){
		countArr[i]+=countArr[i-1];
		
	}
	int outputArr[n];
	for(int i=n-1;i>=0;i--){
		outputArr[--countArr[arr[i]]]=arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i]=outputArr[i];
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	countSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
