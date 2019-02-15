#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+100;
int n,k,dp[maxn][505],cnt;
vector<int>g[maxn];
bool mrk[maxn];

void dfs(int v,int par){
	dp[v][0]=1;
	for(auto u:g[v]){
		if(u!=par){
			dfs(u,v);
			for(int i=1;i<=k;i++)cnt+=dp[u][i-1]*dp[v][k-i];
			for(int i=1;i<=k;i++)dp[v][i]+=dp[u][i-1];
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1);
	cout<<cnt;
}