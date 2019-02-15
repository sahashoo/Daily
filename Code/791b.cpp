#include<bits/stdc++.h>
using namespace std;
const int maxN=150000+12;
int n,m,c[maxN],ver[maxN],part;
bool mark[maxN];
vector<int> adj[maxN];

void dfs(int v){
	mark[v]=true;
	c[v]=part;
	ver[part]++;
	for(int i=0;i<adj[v].size();i++)if(!mark[adj[v][i]])dfs(adj[v][i]);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!mark[i])part++,dfs(i);
	for(int i=1;i<=n;i++)if(adj[i].size()!=ver[c[i]]-1){cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
}