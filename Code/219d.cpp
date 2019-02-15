///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=2e5+7;
int res[MAXN];
vector<pair<int,bool> >g[MAXN];

int dfs(int v,int p){
	int ret=0;
	for(auto u:g[v])
		if(u.F!=p)ret+=u.S+dfs(u.F,v);
	return ret;
}

void calc(int v,int p,int cnt){
	res[v]=cnt;
	for(auto u:g[v])
		if(u.F!=p)calc(u.F,v,cnt+(u.S?-1:1));
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[u].push_back({v,0}),g[v].push_back({u,1});
	calc(1,-1,dfs(1,-1));
	int ind=1;
	for(int i=2;i<=n;i++)if(res[i]<res[ind])ind=i;
	cout<<res[ind]<<'\n';
	for(int i=1;i<=n;i++)if(res[i]==res[ind])cout<<i<<" ";
}
