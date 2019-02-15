#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int N=20,mod=1e9+7;
int n,m,dp[(1<<N)][N];
vector<pair<int,int> >g[N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	memset(dp,63,sizeof(dp));
	
	cin>>n>>m;
	for(int i=0,u,v,w;i<m;i++)
		cin>>u>>v>>w,v--,u--,g[v].pb({u,w}),g[u].pb({v,w});
	
	for(int mask=0;mask<(1ll<<n);mask++){
		for(int u=0;u<n;u++){
			if(mask==(1ll<<u))dp[mask][u]=0;
			else if((1ll<<u)&mask==0)
				dp[mask][u]=mod;
			else
				for(auto v:g[u])
					if(mask&(1<<v.F))
						dp[mask][u]=min(dp[mask][u],dp[mask-(1ll<<u)][v.F]+v.S);
		}
	}
	int res=INF;
	for(int i=0;i<n;i++)res=min(res,dp[(1<<n)-1][i]);
	cout<<res<<'\n';
}
/*
5 6
1 2 1
2 3 2
4 3 3
5 4 4
5 2 6
5 1 5
*/
