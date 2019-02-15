#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,n,k=1000000007;
main(){
	cin>>x>>y>>n;
	ll a[]={x-y,x,y,y-x,-x,-y};
	cout<<(a[n%6]%k+k)%k;
}