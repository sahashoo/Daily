#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,tma,tmi,mi=1<<30,arr[100007],ma=-10;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		mi=min(mi,arr[i]);
		ma=max(ma,arr[i]);
	}
	for(ll i=0;i<n;i++){
		if(arr[i]==ma)	tma++;
		if(arr[i]==mi)	tmi++;
	}
	if(n==1||ma==mi)	cout<<0;
	else cout<<n-tma-tmi;
}