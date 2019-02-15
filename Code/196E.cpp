#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
int from[MAXN],to[MAXN],w[MAXN],par1[MAXN],par2[MAXN],d[MAXN];
set<pair<int,int> >S;
vector<pair<int,int> >g[MAXN];
bool mrk[MAXN];

int root(int v)
{
	return ((par2[v]==-1)?v:par2[v]=root(par2[v]));
}

void dijkstra()
{
	while(S.size())
	{
		auto v=*S.begin();
		S.erase(v);
		if(v.F!=d[v.S])
			continue;
		for(auto u:g[v.S])
		{
			// cout<<"--- "<<u.F<<endl;
			if(d[u.F]>v.F+u.S)
			{
				d[u.F]=v.F+u.S;
				par1[u.F]=par1[v.S];
				S.insert({d[u.F],u.F});
			}
		}
	}
}

int32_t main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>from[i]>>to[i]>>w[i];
		g[from[i]].push_back({to[i],w[i]});
		g[to[i]].push_back({from[i],w[i]});
	}
	int k;
	cin>>k;
	memset(d,63,sizeof d);
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		d[x]=0;
		mrk[x]=1;
		S.insert({0,x});
		par1[x]=x;
	}
	
	dijkstra();
	
	vector<pair<int,pair<int,int> > >edge;
	for(int i=0;i<m;i++)
		edge.push_back({ d[from[i]] + d[to[i]] + w[i] ,{ par1[from[i]] , par1[to[i]] }});
	
	sort(edge.begin(),edge.end());
	memset(par2,-1,sizeof par2);
	int res=0;
	
	for(auto e:edge)
	{
		int v=e.S.F;
		int u=e.S.S;
		v=root(v);
		u=root(u);
		if(v==u)
			continue;
		res+=e.F;
		par2[v]=u;
	}
	
	memset(d,63,sizeof d);
	d[1]=0;
	S.insert({0,1});
	dijkstra();
	
	int mn=1e15;
	for(int i=1;i<=n;i++)
	{
		// cout<<"---- "<<i<<" : "<<d[i]<<" "<<mrk[i]<<endl;
		if(mrk[i])
			mn=min(mn,d[i]);
		
	}
	// cout<<"--- "<<mn<<endl;
	cout<<res+mn<<endl;
}
