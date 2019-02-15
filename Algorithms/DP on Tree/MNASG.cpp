///Maximum Non Adjcent Subgraph Of Tree 
#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int N=1e5+7;
int n,val[N];
vector<int>g[N];
pair<int,int>dp[N];

void dfs(int v,int p){
	int S1=0,S2=0;
    for(auto u:g[v]){
		if(u==p) continue;
		dfs(u,v);
		S1+=dp[u].S;
		S2+=max(dp[u].F,dp[u].S);
    }
    dp[v].F=val[v]+S1;
    dp[v].S=S2;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
    dfs(1,0);
	cout<<max(dp[1].F,dp[1].S);
}