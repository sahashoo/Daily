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
using namespace std;
const int INF=3e18+9237;
const int MAXN=2e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[MAXN];
vector<pair<int,int> >g[MAXN];
set<pair<int,int> >Q;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[v].pb({u,2*w});
		g[u].pb({v,2*w});
	}
	
	for(int i=1;i<=n;i++)
		cin>>a[i],Q.insert({a[i],i});
	
	while(Q.size()){
		int v=Q.begin()->S;
		Q.erase(Q.begin());
		for(auto u:g[v]){
			if(a[u.F]>a[v]+u.S){
				Q.erase({a[u.F],u.F});
				a[u.F]=a[v]+u.S;
				Q.insert({a[u.F],u.F});
			}
		}
	}
	
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
