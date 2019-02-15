/// read! read! read! read! read! read!
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int MAXN=5e2+7;
int l,r;
bool mrk[MAXN];
vector<pair<int,int> >g[MAXN];

void dfs(int v){
	mrk[v]=true;
	for(pair<int,int>x:g[v])
		if(!((x.S>=l&&x.S<=r)||mrk[x.F]))dfs(x.F);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)
		cin>>u>>v,g[v].pb({u,i}),g[u].pb({v,i});
	int q;cin>>q;
	while(q--){
		int ans=0;cin>>l>>r;
		memset(mrk,0,sizeof mrk );
		for(int i=1;i<=n;i++)
			if(mrk[i]==false)dfs(i),ans++;
		cout<<ans<<'\n';
	}
}