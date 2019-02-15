#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int a[MAXN],gc[MAXN],dp[MAXN];
vector<int>g[MAXN];
set<int>st[MAXN];

int gcd(int a,int b){
	return(b?gcd(b,a%b):a);
}

void dfs(int v,int p,int bmm)
{
	for(int x:st[p])
		st[v].insert(gcd(x,a[v]));
	st[v].insert(bmm);
	
	bmm=gcd(bmm,a[v]);
	dp[v]=*(--st[v].end());
	
	for(int u:g[v])
		if(u!=p)
			dfs(u,v,bmm);
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	st[0].insert(0);
	dfs(1,0,0);
	
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// cout<<gc[i]<<" ";
	
	return cout<<endl,0;	
}
