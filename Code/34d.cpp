#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=5e4+7;
int par[maxn],r1,r2,n;
vector<int>g[maxn];
bool mrk[maxn];

void dfs(int v,int p){
	mrk[v]=true;
	par[v]=p;
	for(int i=0;i<g[v].size();i++)if(mrk[g[v][i]]==false)dfs(g[v][i],v);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>r1>>r2;
	for(int i=1;i<=n;i++){
		if(i==r1)continue;
		int v;cin>>v;
		g[v].push_back(i);
		g[i].push_back(v);
	}
	dfs(r2,r2);
	for(int i=1;i<=n;i++){
		if(i==r2)continue;
		cout<<par[i]<<" ";
	}
}
