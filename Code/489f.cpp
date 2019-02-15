#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+7;
int dp[N][N],sum[N];

int32_t main()
{
	int n,m,MOD;
	cin>>n>>m>>MOD;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			char c;
			cin>>c;
			sum[j]+=c-'0';
		}
	
	int t0=0,t1=0;
	for(int i=1;i<=n;i++)
	{
		t0+=(sum[i]==0?1:0);
		t1+=(sum[i]==1?1:0);
	}
	
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(j>=2)
				dp[i-j][j] += ( ((j*(j-1)/2)%MOD) * dp[i-j+2][j-2] )%MOD;
			if(i-j>=2)
				dp[i-j][j] += ( (((i-j)*(i-j-1)/2)%MOD) * dp[i-j-2][j] )%MOD;
			
			dp[i-j][j]+=( (i-j) * j * dp[i-j][j-1] )%MOD;
			dp[i-j][j]%=MOD;
		}
		
	cout<<dp[t1][t0]%MOD<<"\n";
	
}