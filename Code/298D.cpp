///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
map<int,int>mp;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=0,x;i<n;i++)cin>>x,mp[-x]++;
	for(int i=0,x;i<m;i++)cin>>x,mp[-x]--;
	bool c=false;
	int sum=0;
	for(auto x:mp)sum+=x.S,c|=(sum>0);
	cout<<(c?"YES":"NO");
}
