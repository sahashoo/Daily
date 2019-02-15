#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=3e18+9237;
const int maxn=1e5+7;
int c[maxn],res,mn;
bool mrk[maxn];
vector<int>g[maxn];

int dfs(int v){
	mn=min(mn,c[v]);
	mrk[v]=true;
	for(auto u:g[v])
		if(mrk[u]==false)dfs(u);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(mrk[i]==false)mn=INF,dfs(i),res+=mn;
	cout<<res;
}
