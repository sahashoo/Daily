#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=6e3+7;
int c[MAXN],a[MAXN],ans,n;
vector<int>g[MAXN];

void dfs(int v,int p)
{
	int i=lower_bound(a,a+n,c[v])-a;
	int temp=a[i];
	a[i]=c[v];
	ans=max(ans,i);

	for(int u:g[v])
		if(u!=p)
			dfs(u,v);

	a[i]=temp;
}

int32_t main()
{
	// int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	for(int i=0;i<n;i++)
	{
		memset(a,62,sizeof a);
		dfs(i,-1);
	}
	
	cout<<ans+1<<endl;;
}