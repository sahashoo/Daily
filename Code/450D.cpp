#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int N=1e5+7;
vector<pair<int,ll> >g[N];
bool mrk[N];
int ans=0;

main()
{
	// ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int n,m,k;
	// cin>>n>>m>>k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		// cin>>u>>v>>w;
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	priority_queue<pair<ll,int> >Q;
	Q.push({0,1});
	
	for(int i=1;i<=k;i++)
	{
		int u,w;
		// cin>>u>>w;
		scanf("%d %d",&u,&w);
		Q.push({-w,u-n});
	}
	
	while(Q.size())
	{
		pair<ll,int> x=Q.top();
		ll val=-x.F;
		int u=x.S;
		Q.pop();
		
		if(u<=0)
		{
			u+=n;
			if(mrk[u]==true)
				ans+=1;
		}
		
		if(mrk[u]==true)
			continue;
		mrk[u]=true;
		
		for(int i=0;i<g[u].size();i++)
		{
			pair<int,ll>v=g[u][i];
			Q.push({-1ll*(val+v.S),v.F});
		}
	}
	
	cout<<ans;
	
	return cout<<endl,0;	
}