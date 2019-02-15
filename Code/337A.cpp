#include<bits/stdc++.h>
using namespace std;
int arr[100],m,n,sss=9999;
main(){
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>arr[i];
	sort(arr,arr+m);
	for(int i=0;i<=m-n;i++){
		sss=min(sss,arr[i+n-1]-arr[i]);
	}
	cout<<sss;
}