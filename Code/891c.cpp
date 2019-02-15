#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define all(a) a.begin(),a.end()
using namespace std;
const int MAXN=5e5+7;
vector<pair<int,pair<int,int> > > E,qu[MAXN];
vector<pair<int,int> >e[MAXN];
int ans[MAXN],f[MAXN];
vector<pair<pair<int,int>,int> > his;

int root(int v){return f[v]<0?v:root(f[v]);}

void undo()
{
	auto x=his.back();
	his.pop_back();
	if(x.F.F==-1)
		return ;
	f[x.F.F]=x.S;
	f[x.F.S]-=x.S;
}

void merge(int v,int u,int be=0)
{
	v=root(v),u=root(u);
	if(v==u)
	{
		his.push_back({{-1,-1},-1});
		return ;
	}
	if(f[v]>f[u])
		swap(v,u);
	his.push_back({{u,v},f[u]});
	f[v]+=f[u];
	f[u]=v;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(f,-1,sizeof f);
	int n,m,q;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>v>>u>>w;
		v--,u--;
		e[w].push_back({v,u});
		E.push_back({w,{v,u}});
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ans[i]=1;
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int ind;
			cin>>ind;
			ind--;
			qu[E[ind].F].push_back({i,{E[ind].S.F,E[ind].S.S}});
		}
	}
	
	for(int i=0;i<MAXN;i++)
	{
		sort(qu[i].begin(),qu[i].end());
		int ls=-1,cnt=0;
		for(auto Q:qu[i])
		{
			if(Q.F!=ls)
			{
				for(int i=0;i<cnt;i++)
					undo();
				cnt=0;
				ls=Q.F;
			}
			if(root(Q.S.F)==root(Q.S.S))	
				ans[Q.first]=0;
			merge(Q.S.F,Q.S.S);
			cnt++;
		}
		for(int i=0;i<cnt;i++)
			undo();
		for(auto ee:e[i])
			merge(ee.first,ee.second);
		his.clear();
	}
	
	for(int i=0;i<q;i++)
		cout<<(ans[i]?"YES":"NO")<<'\n';
	
	return cout<<endl,0;
}