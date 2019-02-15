#include<bits/stdc++.h>
#define int long long
using namespace std;
int d,k,a,b,t;
 
int32_t main(){
	cin>>d>>k>>a>>b>>t;
	if(d<=k)cout<<d*a;
	else cout<<k*a+(d-k)/k*min(k*a+t,k*b)+min((d-k)%k*a+t,(d-k)%k*b);
}