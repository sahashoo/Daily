///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
// #define int long long
using namespace std;
const int N=33;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
vector<int>g[N];
pair<int,int>pos[N];

void dfs(int v,int p,int way,int tw){
	if(g[v].size()>4)cout<<"NO",exit(0);
	int x=-1;
	for(auto u:g[v]){
		if(u==p)continue;
		x++;x+=(way==x);
		pos[u]={pos[v].F+(dx[x]*tw),pos[v].S+(dy[x]*tw)};
		dfs(u,v,x+(x&1?-1:+1),tw/2);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[v].pb(u),g[u].pb(v);
	dfs(1,0,-1,(1<<30));
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<pos[i].F<<" "<<pos[i].S<<"\n";
}
