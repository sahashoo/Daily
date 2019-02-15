#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,arr[150];
int main(){
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		a*=-1;
		if(a>0){arr[i]=a;}
	}
	sort(arr,arr+149);
	for(ll i=0;i<=m;i++)	ans=ans+arr[149-i];
	cout<<ans<<endl;
}