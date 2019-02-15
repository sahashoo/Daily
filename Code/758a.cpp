#include<bits/stdc++.h>
using namespace std;
int n,arr[150],ma=-1;
long long ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ma=max(ma,arr[i]);
	}
	for(int i=0;i<n;i++){
		ans+=ma-arr[i];
	}
	cout<<ans;
}
