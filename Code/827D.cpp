#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N=2e5+7;
const int K=20;
int dad[N],par[K][N],mx[K][N],dis[N],ans[N];
vector<pair<pair<int,int>,pair<int,int> > >e;
vector<pair<int,int> >g1[N],g2[N];
vector<int>vec[N];
multiset<int>st[N];
bool mrk[N];

int root(int x)
{
	if(dad[x]<0)
		return x;
	return dad[x]=root(dad[x]);
}

void dfs(int v)
{
	for(auto u:g2[v])
		if(u.F!=par[0][v])
		{
			dfs(u.F);
			
			if(st[u.F].size()==0)
				ans[u.S]=-1;
			else
				ans[u.S]=(*st[u.F].begin())-1;
			
			if(st[u.F].size()>st[v].size())
				st[u.F].swap(st[v]);
			
			while(st[u.F].size())
			{
				st[v].insert(*st[u.F].begin());
				st[u.F].erase(st[u.F].begin());
			}
		}
	
	for(auto u:vec[v])
	{
		if(u>0)
			st[v].insert(u);
		else
			st[v].erase(st[v].find(-u));
	}
}

void prep(int v)
{
	for(int i=1;i<K;i++)
	{
		par[i][v]=par[i-1][par[i-1][v]];
		mx[i][v] = max( mx[i-1][v] , mx[i-1][par[i-1][v]] );
	}
	for(auto u:g1[v])
		if(u.F!=par[0][v])
		{
			par[0][u.F]=v;
			mx[0][u.F]=u.S;
			dis[u.F]=dis[v]+1;
			prep(u.F);
		}
}

inline int max_i(int v,int t)
{
	int res=0;
	for(int i=0;i<K;i++)
		if((t&(1<<i))!=0)
		{
			res=max(res,mx[i][v]);
			v=par[i][v];
		}
	return res;
}

inline int par_i(int v,int t)
{
	for(int i=0;i<K;i++)
		if((t&(1<<i))!=0)
			v=par[i][v];
	return v;
}

int lca(int v,int u)
{
	if(dis[v]<dis[u])
		swap(v,u);
	
	v=par_i(v,dis[v]-dis[u]);
	if(v==u)
		return v;
	
	for(int i=K-1;i>=0;i--)
		if(par[i][v]!=par[i][u])
		{
			v=par[i][v];
			u=par[i][u];
		}
		
	return par[0][u];
}

int32_t main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int v,u,w;
		cin>>v>>u>>w;
		e.push_back({{w,i},{u,v}});
	}
	
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)
		dad[i]=-1;
	
	for(auto u:e)
	{
		int x=root(u.S.F),y=root(u.S.S);
		if(x==y)
			continue;
		dad[x]=y;
		mrk[u.F.S]=1;
		
		g1[u.S.F].push_back({u.S.S,u.F.F});
		g2[u.S.F].push_back({u.S.S,u.F.S});
		
		g1[u.S.S].push_back({u.S.F,u.F.F});
		g2[u.S.S].push_back({u.S.F,u.F.S});
	}
	
	prep(1);
	
	for(auto u:e)
	{
		int w=u.F.F,x=u.S.F,y=u.S.S,id=u.F.S;
		if(mrk[id]==true)
			continue;
		
		int p=lca(x,y);
		
		ans[id]=max( max_i(x,dis[x]-dis[p]) , max_i(y,dis[y]-dis[p]) )-1;
		
		vec[x].push_back(w);
		vec[y].push_back(w);
		
		vec[p].push_back(-w);
		vec[p].push_back(-w);
	}
	
	dfs(1);
	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}