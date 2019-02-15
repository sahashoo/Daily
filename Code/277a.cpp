#include<bits/stdc++.h>
using namespace std;
int n,m,ans,b;
bool mark[205];
vector<int>	adj[205];

void dfs(int v){
	mark[v]++;
	for(int i=0;i<adj[v].size();i++){
		if(!mark[adj[v][i]])	dfs(adj[v][i]);
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if(k>0)	b=1;
		for(int j=0;j<k;j++){
			int a;
			cin>>a;
			adj[i].push_back(a+n);
			adj[n+a].push_back(i);
		}
	}
	for(int i=0;i<n;i++){
		if(!mark[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans-b;
}
