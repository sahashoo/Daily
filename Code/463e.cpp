#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define all(a) a.begin(),a.end()
using namespace std;
const int MAXN=2e6+7;
vector<int>pr[MAXN],g[MAXN] ;
vector<pair<int,int> >p[MAXN];
int mx[MAXN],ans[MAXN],c[MAXN];
bool mrk[MAXN];

void dfs(int v,int _p,int k)
{
    mx[v]=-1;
    ans[v]=-1;
    for(int x:pr[c[v]])
    {
		if(p[x].size()&&p[x].back().F>mx[v])
		{
			mx[v]=p[x].back().F;
			ans[v]=p[x].back().S;
		}
		p[x].push_back({k,v});
    }
	
	for(int u:g[v])
		if(u!=_p)
			dfs(u,v,k+1);
	
	for(int x:pr[c[v]])
		p[x].pop_back();
	
}


int32_t main()
{
    int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	for(int i=2;i<MAXN;i++)
		if(mrk[i]==false)
			for(int d=i;d<MAXN;d+=i)
			{
				pr[d].push_back(i);
				mrk[d]=true;
			}
	
    dfs(1,0,0);
    while(q--)
    {
        int x,y;
		cin>>x;
        if(x==1)
        {
            cin>>x;
            cout<<ans[x]<<endl;
        }
        else
        {
            cin>>x>>y;
            c[x]=y;
            dfs(1,0,0);
        }
    }
}