#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,LG=20;
int n,m,d[maxn],h[maxn],anc[maxn][LG+1];
vector<int>g[maxn],sqrtq;

void precompLCA(int v,int p){
	for(auto u:g[v]){
		if(u==p)continue;
		d[u]=h[u]=h[v]+1;
		anc[u][0]=v;
		for(int i=1;i<LG;i++)
			anc[u][i]=anc[anc[u][i-1]][i-1];
		precompLCA(u,v);
	}
}

int LCA(int v,int u){
	if(h[u]>h[v])swap(u,v);
	int depth=h[v]-h[u];
	for(int i=0;i<LG;i++)
		if(depth&(1<<i))v=anc[v][i];
	if(v==u)return v;
	for(int i=LG-1;i>=0;i--)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[v][0];
}


int dist(int u,int v){
	return h[u]+h[v]-2*h[LCA(u,v)];
}

void sqrtcomput(){
	queue<pair<int,int> >Q;
	while(Q.size())Q.pop();
	for(auto x:sqrtq)Q.push({x,0});
	sqrtq.clear();
	while(Q.size()){
		pair<int,int>tmp=Q.front();Q.pop();
		int v=tmp.F;
		if(d[v]!=tmp.S)continue;
		for(auto u:g[v]){
			if(d[u]>d[v]+1){
				d[u]=d[v]+1;
				Q.push({u,d[u]});
			}
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	precompLCA(1,1);
	int sqn=sqrt(m);
	while(m--){
		int t,v;cin>>t>>v;
		if(t==1)sqrtq.push_back(v),d[v]=0;
		else{
			int res=d[v];
			for(auto u:sqrtq)res=min(dist(u,v),res);
			cout<<res<<'\n';
		}
		if(sqrtq.size()>=sqn)sqrtcomput();
	}
}
