#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,arr[990000],ans;
int main(){
	cin>>n;
	for(ll i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(ll i=1;i<=n;i++) ans+=abs(i-arr[i-1]);
	cout<<ans;
}