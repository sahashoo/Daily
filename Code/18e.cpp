#include<bits/stdc++.h>
// #define int long long
#define F first
#define S second
using namespace std;
const int MAXN=507;
const int N=26;
int dp[MAXN][N][N];
pair<int,int>par[MAXN][N][N];
string ans[MAXN];

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		ans[i]=s;
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
			{
				if(k==j)continue;
				
				for(int p=0;p<m;p++)
				{
					if(p%2==1 && s[p]-'a'!=k)
						dp[i][j][k]++;
					if(p%2==0 && s[p]-'a'!=j)
						dp[i][j][k]++;
				}
				int res=1e15+7;
				for(int _j=0;_j<N;_j++)
				if(_j!=j)	
					for(int _k=0;_k<N;_k++)
					if(_k!=k&&_k!=_j)
					{
						if(res>dp[i-1][_j][_k])
						{	
							res=dp[i-1][_j][_k];
							par[i][j][k]={_j,_k};
						}
					}
				dp[i][j][k]+=res;
			}
	}
	
	int mj=0,mk=1;
	for(int j=0;j<N;j++)
		for(int k=0;k<N;k++)	
			if(j!=k&&dp[n][j][k]<dp[n][mj][mk]) 
				mj=j,mk=k;
			
	cout<<dp[n][mj][mk]<<endl;
	
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<m;j++)
		{
			if(j&1)
				ans[i][j]='a'+mk;
			else 
				ans[i][j]='a'+mj;
		}	
		int sj=mj,sk=mk;
		mj=par[i][sj][sk].F;
		mk=par[i][sj][sk].S;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}