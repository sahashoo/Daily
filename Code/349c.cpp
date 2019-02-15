///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long mx=0,x,sum=0,n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>x,sum+=x,mx=max(mx,x);
	cout<<max(mx,(sum-1)/(n-1)+1);
}