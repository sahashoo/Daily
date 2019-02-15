///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,LOG=17;
int n,q,h[maxn],par[maxn][LOG];
vector<int>g[maxn],s[maxn],nill;

void dfs(int v,int H,int P){
	h[v]=H;par[v][0]=P;
	for(int i=1;i<LOG;i++)par[v][i]=par[par[v][i-1]][i-1];
	for(auto u:g[v])dfs(u,H+1,v);
}

int lca(int v,int u){
	if(h[v]>h[u])swap(u,v);
	for(int i=0;i<LOG;i++)if(((h[u]-h[v])>>i)%2)u=par[u][i];
	for(int i=LOG-1;i>=0;i--)if(par[v][i]!=par[u][i])v=par[v][i],u=par[u][i];
	return (v==u?v:par[v][0]);
}

int check(int f,int s,int t){
	int res=0;
	int fs=lca(f,s),ft=lca(f,t),st=lca(s,t);
	bool c1=(fs==f),c2=(ft==f);
	if(c1!=c2)return 1;
	if(c1)res=max(res,h[st]-h[f]);
	else if(fs!=ft)res=max(res,h[f]-max(h[fs],h[ft]));
	else res=max(res,h[f]+h[st]-2*h[ft]);
	return res+1;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u;cin>>u;u--;
		g[u].push_back(i);
	}
	dfs(0,0,0);
	while(q--){
		int a,b,c;cin>>a>>b>>c;a--;b--;c--;
		cout<<max(check(a,b,c),max(check(b,a,c),check(c,b,a)))<<'\n';
	}
}