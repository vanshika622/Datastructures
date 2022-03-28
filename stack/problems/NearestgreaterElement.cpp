#include<bits/stdc++.h>

using namespace std;
//bruteforce approach
vector<int> Nearestgreater(int arr[], int n){
	vector<int>res;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[i]){
				res.push_back(arr[j]);
				break;
			}
		}
	}
	res.push_back(-1);
	
	return res;
}
//using stack---O(n)
vector<int> Nearestgreaterele(int arr[], int n){
	vector<int>res;
	stack<int>st;
	for(int i=n-1;i>=0;i--){
		if(st.size()==0){
			res.push_back(-1);
		}
		else if(st.size()>0 && st.top()>arr[i]){
			res.push_back(st.top());
		}
		else if(st.size()>0 && st.top()<=arr[i]){
			while(st.size()>0 && st.top()<=arr[i]){
				st.pop();
			}
			if(st.size()==0){
				res.push_back(-1);
			}
			else{
				res.push_back(st.top());
			}
			
		}
		st.push(arr[i]);
	}
	reverse(res.begin(),res.end());
	
	return res;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	vector<int>ans;
	ans=Nearestgreater(arr,n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	ans=Nearestgreaterele(arr,n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
