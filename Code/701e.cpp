///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+7;
int n,k;
long long res;
bool mrk[maxn];
vector<int>g[maxn];

int dfs(int v,int p){
	int cnt=(mrk[v]?1:0);
	for(auto u:g[v])
		if(u!=p)cnt+=dfs(u,v);
	res+=min(cnt,k-cnt);
	return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;k*=2;
	for(int i=0,a;i<k;i++)cin>>a,mrk[a]=true;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u].pb(v),g[v].pb(u);
	dfs(1,0);
	cout<<res;
}
