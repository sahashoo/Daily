///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
const int maxn=3e3+7,INF=1e18+7;
int mnv[maxn],mn[maxn];
bool mrk[maxn];
vector<pair<int,int> >g[maxn],e;

void dfs(int v){
	mrk[v]=true;int t=0;
	for(auto u:g[v]){
		if(mrk[u.F]==false){
			dfs(u.F);
			mnv[v]+=mnv[u.F];
			if(u.S==0)mnv[v]++;
			t=min(t,mn[u.F]-mnv[u.F]+(u.S==1?1:-1));
		}
	}
	mn[v]=mnv[v]+t;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;u--;v--;
		g[u].push_back({v,1});
		g[v].push_back({u,0});
		e.push_back({u,v});
	}
	int ans=INT_MAX;
	for(auto E:e){
		for(int j=0;j<=n;j++)mrk[j]=false,mnv[j]=0;
		mrk[E.F]=true;mrk[E.S]=true;
		dfs(E.F);dfs(E.S);
		ans=min(ans,mn[E.F]+mn[E.S]);
	}
	cout<<(n==1?0:ans);
}