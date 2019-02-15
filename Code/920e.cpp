#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=2e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

set<int> g[MAXN] , st;
vector<int> scc;
int n,cnt;

void dfs(int v)
{	
	st.erase(v);
	cnt++;
	
	auto it = st.begin();
	
	while(it != st.end())
	{
		int x = *it;
		
		if(g[v].find(x) == g[v].end())
			dfs(x);
		
		it = st.upper_bound(x);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int m;cin >> n >> m;
	for(int i = 0; i < m ; i++)
	{
		int u , v;cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	
	FOR(i,1,n)st.insert(i);
	
	FOR(i,1,n)
		if(st.find(i) != st.end())
		{
			cnt = 0;
			dfs(i);
			scc.pb(cnt);
		}
		
	sort(all(scc));
	
	cout<< sz(scc) <<'\n';
	for(int x : scc)
		cout<< x <<" ";
	
}
