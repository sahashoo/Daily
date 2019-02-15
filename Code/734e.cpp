///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAXN=2e5+7;
int maxV,maxH;
bool mrk[MAXN],col[MAXN];
vector<int>g[MAXN],cnt[2];

void dfs(int v,int p,int h){
	if(h>maxH)maxH=h,maxV=v;
	for(auto u:g[v])
		if(u!=p)dfs(u,v,(col[u]!=col[v])+h);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>col[i];
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[u].pb(v),g[v].pb(u);
	dfs(1,0,0);maxH=0;dfs(maxV,0,0);
	cout<<(maxH+1)/2;
}
