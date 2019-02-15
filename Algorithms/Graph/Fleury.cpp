#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
vector<int>g[MAXN],tour;
set<int>Se;

void fleury(int v)
{
	for(int u:g[v])
	{	
		if(Se.find({v,u})!=Se.end())
		{
			Se.erase({v,u});
			Se.erase({u,v});
			fleury(u);
		}
	}
	tour.push_back(v);
}

main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
    {
		int v,u;
		cin>>v>>u;
		g[v].push_back(u);
		g[u].push_back(v);
		Se.insert({u,v});
		Se.insert({v,u});
    }
	fleury(1);
}
