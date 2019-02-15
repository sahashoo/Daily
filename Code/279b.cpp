#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,t,arr[110000],ans,a;
int main(){
	cin>>n>>t;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		arr[i]=arr[i-1]+x;
		if(arr[i]-arr[a]>t) a++;
		ans=max((i-a),ans);
	}
	cout<<ans<<endl;
}