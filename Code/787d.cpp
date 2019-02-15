#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int INF=1e18+153;
const int MOD=1e9+7;
const int MAXN=3e5+7;
vector<pair<int,int> >g[5*MAXN];
int dist[5*MAXN],t1=2*MAXN,t2=3*MAXN;

void build(int v,int l,int r)
{
	if(r-l<2)
	{
		g[v].push_back({t1+l,0});
		g[t1+l].push_back({v,0});
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	build(lc,l,mid);
	build(rc,mid,r);
	g[v].push_back({lc,0});
	g[v].push_back({rc,0});
}

void build2(int v,int l,int r)
{
	if(r-l<2)
	{
		g[v+t2].push_back({t1+l,0});
		g[t1+l].push_back({v+t2,0});
		return;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	build2(lc,l,mid);
	build2(rc,mid,r);
	g[lc+t2].push_back({v+t2,0});
	g[rc+t2].push_back({v+t2,0});
}

void add1(int id,int st,int en,int l,int r,int v,int w)
{
	if(l>=en||st>=r)
		return;
	if(l<=st&&en<=r)
	{
		g[v+t1].push_back({id,w});
		return;
	}
	int mid=(en+st)/2,lc=id*2,rc=id*2+1;
	add1(lc,st,mid,l,r,v,w);
	add1(rc,mid,en,l,r,v,w);
}

void add2(int id,int st,int en,int l,int r,int v,int w)
{
	if(l>=en||st>=r)
		return;
	if(l<=st&&en<=r)
	{
		g[id+t2].push_back({v+t1,w});
		return;
	}
	int mid=(en+st)/2,lc=id*2,rc=id*2+1;
	add2(lc,st,mid,l,r,v,w);
	add2(rc,mid,en,l,r,v,w);
}

void dijkstra(int root)
{
	for(int i=1;i<5*MAXN;i++)
		dist[i]=INF;
	dist[root]=0;
	set<pair<int,int> >S;
	for(int i=1;i<5*MAXN;i++)
		S.insert({dist[i],i});
	
	while(S.size())
	{
		pair<int,int>v=*S.begin();
		S.erase(*S.begin());
		
		for(auto u:g[v.S])
		{
			if(dist[u.F]>v.F+u.S)
			{
				S.erase({dist[u.F],u.F});
				dist[u.F]=v.F+u.S;
				S.insert({dist[u.F],u.F});
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,q,s;
	cin>>n>>q>>s;
	s--;
	build(1,0,n);
	build2(1,0,n);
	
	for(int i=0;i<q;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			g[u+t1].push_back({v+t1,w});
		}
		else if(type==2)
		{
			int v,l,r,w;
			cin>>v>>l>>r>>w;
			v--,l--;
			add1(1,0,n,l,r,v,w);
		}
		else
		{
			int v,l,r,w;
			cin>>v>>l>>r>>w;
			v--,l--;
			add2(1,0,n,l,r,v,w);
		}
	}
	
	dijkstra(t1+s);
	
	for(int i=0;i<n;i++)
	{
		if(dist[t1+i]==INF)
			dist[t1+i]=-1;
		cout<<dist[t1+i]<<" ";
	}
	
	return cout<<endl,0;
}