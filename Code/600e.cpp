#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define all(a) a.begin(),a.end()
using namespace std;
const int N=2e5+7;
int pnt[N],v[N],nxt[N],mrk[N],sz[N],son[N],ind,cx,sum,num[N],ans[N],col[N];

void add(int x,int y)
{
	ind+=1;
	nxt[ind]=pnt[x];
	pnt[x]=ind;
	v[ind]=y;
	ind+=1;
	nxt[ind]=pnt[y];
	pnt[y]=ind;
	v[ind]=x;
}

void solve(int x,int f)
{
	sz[x]=1;
	for(int i=pnt[x];i;i=nxt[i])
	{
		if(v[i]==f) 
			continue;
	    solve(v[i],x);
		sz[x]+=sz[v[i]];
		if(sz[v[i]]>sz[son[x]])
			son[x]=v[i];
	}
}

void calc(int x,int f,int val)
{
	num[col[x]]+=val;
	if(val>0&&num[col[x]]>=cx)
	{
		if(num[col[x]]>cx)
		{
			sum=0;
			cx=num[col[x]];
		}
		sum+=col[x];
	}
	for(int i=pnt[x];i;i=nxt[i])
		if(v[i]!=f&&mrk[v[i]]==0)
			calc(v[i],x,val);
}

void dfs(int x,int f,bool k=0)
{
	for(int i=pnt[x];i;i=nxt[i])
		if(v[i]!=f&&v[i]!=son[x])
			dfs(v[i],x,0);
	if(son[x])
	{
		dfs(son[x],x,1);
		mrk[son[x]]=1;
	}
	calc(x,f,1);
	ans[x]=sum;
	if(son[x])
		mrk[son[x]]=0;
	if(k==0)
	{		
		calc(x,f,-1);
		cx=0;
		sum=0;
	}
}

int32_t main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	solve(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
} 