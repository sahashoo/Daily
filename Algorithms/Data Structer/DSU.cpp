#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;

struct dsu
{
	int par[MAXN],sz[MAXN];
	void build()
	{
		for(int i=0;i<MAXN;i++)
			par[i]=i,sz[i]=1;
	}
	int find(int v)
	{
		return par[v]==v?v:par[v]=find(par[v]);
	}
	bool connect(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v)return true;
		if(sz[v]<sz[u])swap(u,v);
		sz[v]+=sz[u];
		par[u]=v;
		return false;
	}
}T;

int main(){
}