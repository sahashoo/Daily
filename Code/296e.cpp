#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MOD=1e9+7;
const int N=507;
int cnt[2],dp[2][N][N],t[2][N][N],c[N][N];

int32_t main()
{
	for(int i=0;i<N;i++)c[i][i]=c[i][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;	
		
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cnt[x/50-1]++;
	}
	
	queue<pair<pair<int,int>,int> > Q;
	Q.push({{cnt[0],cnt[1]},1});
	dp[0][cnt[0]][cnt[1]]=t[0][cnt[0]][cnt[1]]=1;
	
	while(Q.size())
	{
		int x=Q.front().F.F;
		int y=Q.front().F.S;
		int p=Q.front().S;
		bool m=(p==1?0:1);
		int _x=(p!=-1?x:cnt[0]-x);
		int _y=(p!=-1?y:cnt[1]-y);
		Q.pop();		

		for(int i=0;i<=_x;i++)
		{
			for(int j=0;j<=_y;j++)
			{
				if((i!=0||j!=0)&& i*50+j*100<=k)
				{
					int a=x-p*i,b=y-p*j;
					
					if( dp[!m][a][b]==0 || dp[m][x][y] < dp[!m][a][b] )
					{
						t[!m][a][b]+=(((t[m][x][y]*c[_x][i])%MOD)*c[_y][j])%MOD;
						t[!m][a][b]%=MOD;
					}
					if(dp[!m][a][b]==0)
					{
						dp[!m][a][b]=dp[m][x][y]+1;
						Q.push({{a,b},-p});	
					}						
				}	
			}
		}				
	}
	
	cout<<dp[1][0][0]-1<<" "<<t[1][0][0];
}