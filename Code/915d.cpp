#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=550;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
vector<set<pair<int,int> > >cyc;
vector<int>vec,g[MAXN];
int mrk[MAXN],cnt;

void dfs(int v){
	mrk[v]=1;
	for(int u:g[v])
		if(mrk[u]==0)dfs(u);
		else cnt+=(mrk[u]==1);
	mrk[v]=2;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
		cin>>u>>v,g[u].pb(v);
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(mrk,0,sizeof mrk );
		dfs(i);
		for(int j=1;j<=n;j++)
			if(mrk[j]==false)dfs(j);
		if(cnt<=1)return cout<<"YES",0;
	}
	cout<<"NO";
}
