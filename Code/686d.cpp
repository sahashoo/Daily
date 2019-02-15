#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=3e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int t[MAXN],w[MAXN],ans[MAXN],par[MAXN];
vector<int>g[MAXN];

void dfs(int v){
	t[v]=1;
	int ind=0;
	for(int u:g[v]){
		dfs(u);
		t[v]+=t[u];
		if(t[ind]<t[u]){
			ind=u;
			w[v]=t[u];
		}
	}
	if(t[v]==1){
		ans[v]=v;
	}
	else{
		int c=ans[ind];
		while(max(t[v]-t[c],w[c])*2>t[v])
			c=par[c];
		ans[v]=c;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=2;i<=n;i++){
		int v;cin>>v;
		g[v].pb(i);
		par[i]=v;
	}
	dfs(1);
	while(q--){
		int v;
		cin>>v;
		cout<<ans[v]<<'\n';
	}
}
