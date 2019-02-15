#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+12;
int n,rang[MAXN],mx,maxrang;
vector<int>adj[MAXN];

void dfs(int v,int p){
	int cnt=1;
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			if(cnt==rang[v]||cnt==rang[p])cnt++;
			if(cnt==rang[v]||cnt==rang[p])cnt++;
			rang[adj[v][i]]=cnt++;
			maxrang=max(maxrang,cnt);
			dfs(adj[v][i],v);
		}
	}
}

int main(){	
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(adj[mx].size()<=adj[v].size())mx=u;
		if(adj[mx].size()<=adj[u].size())mx=v;
	}
	rang[mx]=1;
	dfs(mx,0);
	cout<<maxrang-1<<endl;
	for(int i=1;i<=n;i++)cout<<rang[i]<<" ";
}