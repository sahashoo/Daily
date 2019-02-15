#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=2e5+7,mod=1e9+7,lgN=22;
long long anc[N][lgN],dst[N][lgN],dad[N],tpw[N];
vector<int>g[N],tr[N],cac[N];

int lca_h[N];
void precompLCA(int v,int p){
	lca_h[v]=lca_h[p]+1;
	anc[v][0]=p;
	dst[v][0]=dad[v];
	for(int i=1;i<lgN;i++)
		anc[v][i]=anc[anc[v][i-1]][i-1],
		dst[v][i]=dst[v][i-1]+dst[anc[v][i-1]][i-1];
	for(int u:g[v])
		if(u!=p)precompLCA(u,v);
	return ;
}

pair<int,int> get_par(int v,int u){
	long long w=0;
	for(int i=0;i<lgN;i++)
		if((u>>i)&1)
			w+=dst[v][i],v=anc[v][i];
	return {v,w};
}

int lca(int v,int u){
	if(lca_h[v]<lca_h[u])swap(v,u);
	pair<int,int> x=get_par(v,lca_h[v]-lca_h[u]);
	v=x.F;
	if(v==u)return x.S+dad[v];
	long long ret=x.S;
	for(int i=lgN-1;i>=0;i--)
		if(anc[v][i]!=anc[u][i])
			ret+=dst[v][i]+dst[u][i],
			v=anc[v][i],u=anc[u][i];
	return ret+dad[anc[v][0]]+dad[v]+dad[u];
}

int dfs_h[N],flg[N],par[N];
vector<pair<int,int> >nd_mrg;
void dfs(int v,int p){
	dfs_h[v]=dfs_h[p]+1;
	flg[v]=v,par[v]=p;
	for(int u:cac[v])
		if(flg[u]&&u!=p&&dfs_h[u]<dfs_h[v])nd_mrg.pb({v,u});
		else if(flg[u]==0)dfs(u,v);
	return;
}

bool mrk[N];
void merge(pair<int,int> x){
	set<int>st;
	long long y=x.F;
	while(y!=x.S){
		st.insert(y);
		dad[y]=1;
		flg[y]=x.F;
		mrk[y]=1;
		y=par[y];
	}
	st.insert(y);
	dad[y]=1;
	flg[y]=x.F;
	for(int i:st)
		for(int j:cac[i])
			if(st.find(j)==st.end())
				tr[x.F].pb(j);
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,q,u,v;cin>>n>>m;
	tpw[0]=1;
	for(int i=1;i<=n;i++)
		tpw[i]=(2*tpw[i-1])%mod;
	for(int i=0;i<m;i++)
		cin>>u>>v,cac[v].pb(u),cac[u].pb(v);
	dfs(1,1);
	for(pair<int,int> i:nd_mrg)merge(i);
	for(int i=1;i<=n;i++)
		if(mrk[i]==false)tr[i]=cac[i];
	for(int i=1;i<=n;i++)
		for(int j:tr[i])
			g[i].pb(flg[j]);	
	precompLCA(flg[1],-1);
	// int u,v,q;
	cin>>q;
	while(q--)
		cin>>u>>v,cout<<tpw[lca(flg[v],flg[u])]<<'\n';
}
