#include<bits/stdc++.h>
using namespace std;
int n,arr[110000],b[110000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=n-2;i>=0;i--){
		b[i]=arr[i+1]-arr[i]+1;
		arr[i]=max(arr[i+1],arr[i]);
		if(b[i]<0)	b[i]=0;
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
} 