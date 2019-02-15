#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,arr[9000],ans;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		arr[a]++;
		ans=max(arr[a],ans);
	}
	cout<<n-ans;
}