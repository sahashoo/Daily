///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
vector<int>res;
vector<pair<int,bool> >g[maxn];
bool col[maxn],mrk[maxn];

void dfs(int v,int c){
	mrk[v]=true;
	col[v]=c;
	if(c)res.push_back(v);
	for(auto u:g[v]){
		if(mrk[u.F]==false)dfs(u.F,c^u.S);
		else if(col[v]==col[u.F]&&u.S==1)cout<<"Impossible",exit(0);
		else if(col[v]!=col[u.F]&&u.S==0)cout<<"Impossible",exit(0);
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,t;cin>>u>>v>>t;t^=1;
		g[u].push_back({v,t});
		g[v].push_back({u,t});
	}
	for(int i=1;i<=n;i++)if(mrk[i]==false)dfs(i,1);
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x<<" ";
}
