#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
set<ll> t;
vector<ll>	ans;
int main(){
	cin>>n>>m;
	for(ll i=0;i<n;i++){ll a;cin>>a;t.insert(a);}
	for(ll i=1;i<=m;i++){if(!t.count(i)){m-=i;ans.push_back(i);}}
	cout<<ans.size()<<endl;
	for(ll i=0;i<ans.size();i++){cout<<ans[i]<<" ";}
}