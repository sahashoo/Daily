#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=5e5+7;
vector<pair<int,int> >g[MAXN];
vector<int>tour;
bool mrk[MAXN];

void dfs(int v)
{
	if(g[v].empty())
		return ;
    while(g[v].size())
    {
        auto e=g[v].back();
        g[v].pop_back();
        if(mrk[e.S]==false)
        {
            mrk[e.S]=true;
            dfs(e.F);
        }
    }
    tour.push_back(v);
}

int32_t main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[v].push_back({u,i});
		g[u].push_back({v,i});
    }
	
	int temp=-1;
    for(int i=1;i<=n;i++)
		if(g[i].size()%2==1)
        {
			if(temp==-1)
				temp=i;
			else
            {
                m++;
                g[i].push_back({temp,m});
                g[temp].push_back({i,m});
                temp=-1;
            }
        }
    if(m%2==1)
    {
        m++;
        g[1].push_back({1,m});
    }
	
    dfs(1);
	cout<<m<<'\n';
    for(int i=1;i<tour.size();i++)
    {
        if(i%2)
			cout<<tour[i]<<" "<<tour[i-1]<<"\n";
		else
			cout<<tour[i-1]<<" "<<tour[i]<<"\n";
    }
}