#include<bits/stdc++.h>
#define size(a) (int)a.size()
//#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=20;
vector<int>g[N];
long long dp[(1<<N)][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for(int i=0;i<N;i++)
	{
		dp[(1<<i)][i]=1;
	}
	
	int n,m;cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		v--;u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	long long cnt=0;
	for(int msk=1;msk<(1<<n);msk++)
	{
		for(int u=0;u<n;u++)
		{
			if(msk&(1<<u))
			{
				int Fbit;//=(msk&(msk-1));
				for(int i=0;i<n;i++)
					if((1<<i)&msk)
					{
						Fbit=i;
						break;
					}
				if(u==Fbit)
					continue;
				bool ch=false;
				for(auto v:g[u])
				{
					if((msk-(1<<u))&(1<<v))
						dp[msk][u]+=dp[msk-(1<<u)][v];
					if(v==Fbit)
						ch=true;
				}
				cnt+=__builtin_popcount(msk)>2?dp[msk][u]*ch:0;
			}
		}
	}
	cout<<cnt/2;
}
