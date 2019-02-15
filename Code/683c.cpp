#include<bits/stdc++.h>
#define q first
#define w second
using namespace std;
const int maxn=2e5+10;
int n,k,col[maxn];
vector<pair<int,int> > g[maxn];
vector<int> d[maxn];

void dfs(int v,int p){
	int mx=1;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i].q!=p){
			if(mx==col[v])mx++;
			col[g[v][i].q]=mx;
			d[mx].push_back(g[v][i].w);
			k=max(mx,k);
			mx++;
			dfs(g[v][i].q,v);
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int v,u;
		cin>>v>>u;
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
    }
	dfs(1,0);
	cout<<k<<endl;
	for(int i=1;i<=k;i++){
		cout<<d[i].size()<<" ";
		for(int j=0;j<d[i].size();j++)cout<<d[i][j]<<" ";
		cout<<endl;
    }
}