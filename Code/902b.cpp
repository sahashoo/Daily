///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
vector<int>g[MAXN];
int col[MAXN],res;

void dfs(int v,int p,int c){
	if(c!=col[v])c=col[v],res++;
	for(auto u:g[v])
		if(u!=p)dfs(u,v,c);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>col[i];
	dfs(1,-1,0);
	cout<<res;
}
