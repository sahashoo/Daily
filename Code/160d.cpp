#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int MAX=1e5+9;
const int MAX2=1e6+9;
vector<pair<int,int> > g[MAX];
vector<pair<pair<int,int>,int> > edge[MAX2];
int n,m,u,v,w,f[MAX],h[MAX];
string ans[MAX];
bool mark[MAX];
vector<int> ve; 

int root(int v){
	return f[v]<0?v:f[v]=root(f[v]);
}

void merge(int v,int u)
{
	v=root(v);
	u=root(u);
	if(v==u)
		return ;
	if(f[u]<f[v])
		swap(v,u);
	f[v]+=f[u],f[u]=v;
}

int dfs(int v,int p=-1)
{
	mark[v]=true;
	int ret=1e9;
	for(auto u:g[v]) 
		if(u.S!=p)
		{
			if(mark[u.F]==false) 
			{
				h[u.F]=h[v]+1;
				int r=dfs(u.F,u.S);
				ret=min(ret,r);
				if(r<=h[v])ans[u.S]="at least one"; 
			}
			else
			{
				ret=min(ret,h[u.F]);
				ans[u.S]="at least one";
			}
		}
	return ret;
}

int32_t main()
{
	memset(f,-1,sizeof f);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>v>>u>>w;
		v--,u--;
		edge[w].push_back({{v,u},i});
	}
	for(int i=0;i<MAX2;i++)
	{
		for(auto e:edge[i])
		{
			int a=root(e.F.F),b=root(e.F.S);
			if(a==b) 
			{
				ans[e.S]="none";
				continue;
			}
			g[a].push_back({b,e.S});
			g[b].push_back({a,e.S});
			ve.push_back(a);
			ve.push_back(b);
		}
		for(auto i:ve)
			if(mark[i]==false)
			{
				h[i]=0;
				dfs(i);
			}
		for(auto e:edge[i])
			merge(e.F.F,e.F.S);
		for(auto i:ve)
		{
			mark[i]=false;
			g[i].clear();
		}
		ve.clear();
	}
	for(int i=0;i<m;i++)
		cout<<(ans[i]==""?"any":ans[i])<<endl;
	return 0;
}