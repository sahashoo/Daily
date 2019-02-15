///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+7;
int num[maxn];
long long inc[maxn],red[maxn];
vector<int>g[maxn];

void dfs(int v,int p){
	for(auto u:g[v])
		if(u!=p)dfs(u,v),inc[v]=max(inc[v],inc[u]),red[v]=max(red[v],red[u]);
	long long tmp=num[v]+inc[v]-red[v];
	if(tmp<0)inc[v]-=tmp;
	else red[v]+=tmp;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[v].pb(u),g[u].pb(v);
	for(int i=1;i<=n;i++)cin>>num[i];
	dfs(1,-1);
	cout<<inc[1]+red[1];
}
