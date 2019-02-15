/// read! read! read! read! read! read!
#include<bits/stdc++.h>
#define int long long
#define merg mmd
using namespace std;
const int MAXN=1e6+7;
int par[MAXN],deg[MAXN],toghe,cnt;
bool mrk[MAXN];

int getpar(int v){
	return par[v]==v ? v:(par[v]=getpar(par[v])) ;
}

int h[MAXN];
void merg(int u,int v){
	if(h[v]<h[u])par[v]=u;
	else
		h[u]+=(h[u]==h[v]),par[u]=v;
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;i++)par[i]=i;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		if(u==v)toghe++;
		else deg[u]++,deg[v]++;
		int x=getpar(u),y=getpar(v);
		if(x!=y)merg(y,x),cnt++;
		mrk[u]=mrk[v]=true;
	}
	int temp=0;
	for(int i=1;i<=n;i++)
		temp+=(mrk[i]);
	if(cnt!=temp-1)return cout<<0,0;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=deg[i]*(deg[i]-1)/2;
	ans+=toghe*(m-toghe);
	ans+=toghe*(toghe-1)/2;
	cout<<ans;
}