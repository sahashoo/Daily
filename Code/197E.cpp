#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define node pair<pair<int,int>,int>
using namespace std;
const int MAXN=2e3+7;
vector<int>g[MAXN];
int ans[MAXN],cnt[MAXN];
node p[MAXN];

void dfs(int v,int par)
{
	cnt[v]=1;
	for(int u:g[v])
		if(u!=par)
		{
			dfs(u,v);
			cnt[v]+=cnt[u];
		}
}

pair<int,int> m;
inline bool cmp(const node &a,const node &b)
{
	return (a.F.S-m.S)*(b.F.F-m.F)-(a.F.F-m.F)*(b.F.S-m.S) > 0;
}
inline void make_OK(int l,int r)
{
	m=p[l].F;
	sort(p+l+1,p+r,cmp);
}

void solve(int v,int par,int ind)
{
	make_OK(ind,ind+cnt[v]);
	ans[p[ind].S]=v;
	ind++;
	for(int u:g[v])
		if(u!=par)
		{
			solve(u,v,ind);
			ind+=cnt[u];
		}
}

int32_t main()
{
	int n;cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	int mn=0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i]={{x,y},i};
		if(p[i].F.S>p[mn].F.S)
			mn=i;
	}
	swap(p[mn],p[0]);
	dfs(0,-1);
	solve(0,-1,0);

	for(int i=0;i<n;i++)
		cout<<ans[i]+1<<" ";
}