#include<bits/stdc++.h>
using namespace std;
int n,x[100007],y[100007],mark[100007],ans;
vector<int> adj[100007];

void dfs(int v){
	mark[v]++;
	for(int i=0;i<adj[v].size();i++){
		if(!mark[adj[v][i]])dfs(adj[v][i]);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		for(int j=i-1;j>=0;j--){
			if(x[i]==x[j]||y[i]==y[j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!mark[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans-1;
}