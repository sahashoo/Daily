#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,x,ma,par[maxn],dis[maxn],dist[maxn];
vector<int> g[maxn];

void dfs(int v,int p){
	par[v]=p;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]-par[v]){
			dis[g[v][i]]=dis[v]+1;
			dfs(g[v][i],v);
		}
	}
}

void dfs2(int v,int p=0){
	if(dist[v]>=dis[v])return ;
	if(dis[ma]<=dis[v])ma=v;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]-p){
			dist[g[v][i]]=dist[v]+1;
			dfs2(g[v][i],v);
		}
	}
}

int32_t main(){
	cin>>n>>x;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs2(x,0);
	cout<<2*dis[ma]<<endl;
}