#include<bits/stdc++.h>
using namespace std;
int n,arr[100007];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)arr[i]=i+1;
	do{
		for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
	}while(next_permutation(arr,arr+n));
	
}