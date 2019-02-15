#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int pos[MAXN],sz[MAXN],bgn[MAXN],col[MAXN],bc[MAXN];
vector<int>g[MAXN],emp;
vector<vector<int> >c;

void getsize(int v,int p)
{
	sz[v]=1;
	int mx=0,b=-1;
	for(int u:g[v])
	{
		if(u!=p)
		{
			getsize(u,v);
			if(sz[u]>mx)
				mx=sz[u],b=u;
		}
	}
	bc[v]=b;
}

void hld(int v,int p,int id)
{
	c[id].push_back(v);
	col[v]=id;
	pos[v]=c.size()-1;
	for(int u:g[v])
	{
		if(u!=p&&u!=bc[v])
		{
			int i=c.size();
			c.push_back(emp);
			bgn[i]=u;
			hld(u,v,i);
		}
	}
	hld(bc[v],v,id);
}

int32_t main(){
	
}