///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+7;
int par[MAXN],dim[MAXN],sz[MAXN],maxL,maxV;
bool mrk[MAXN];
vector<int>g[MAXN];

void dfs(int v,int p,int h){
	if(h>maxL)maxL=h,maxV=v;
	for(auto u:g[v])
		if(u!=p)dfs(u,v,h+1);
}

int getpar(int v){return par[v]==v?v:par[v]=getpar(par[v]);}

inline void merg(int u,int v){
	u=getpar(u);
	v=getpar(v);
	if(u==v)return ;
	if(sz[u]<sz[v])swap(u,v);
	sz[u]+=sz[v];
	par[v]=u;
	int tmp=(dim[v]+1)/2;
	tmp+=(dim[u]+1)/2;tmp++;
	dim[u]=max(max(dim[u],dim[v]),tmp);
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	for(int i=0;i<=n;i++)par[i]=i,sz[i]=1,dim[i]=0;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
		merg(u,v);
	}
	for(int i=0;i<=n;i++)dim[i]=0;
	for(int i=1;i<=n;i++){
		int p=getpar(i);
		if(mrk[p]==false){
			mrk[p]=true;
			maxL=-1,maxV=-1;
			dfs(p,0,-1);
			maxL=-1;
			dfs(maxV,0,0);
			dim[p]=maxL;
		}
	}
	while(q--){
		int t,u,v;cin>>t>>u;
		if(t==1)cout<<dim[getpar(u)]<<'\n';
		else cin>>v,merg(u,v);
	}
}
