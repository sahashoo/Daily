#include<bits/stdc++.h>
using namespace std;
long long n,arr[100007];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr[a]+=a;
	}
	for(int i=2;i<=100000;i++){
		arr[i]=max(arr[i-1],arr[i]+arr[i-2]);
	}
	cout<<arr[100000];
}