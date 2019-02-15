#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=90;
int a[MAXN],dp[MAXN][2];
bool k[MAXN];

int32_t main()
{
	a[0]=a[1]=1;
	for(int i=2;i<MAXN;i++)
		a[i]=a[i-1]+a[i-2];
	int t;
	cin>>t;
	while(t--)
	{
		memset(k,0,sizeof k);
		int n,p,l=0,ans=0;
		cin>>n;
		for(int i=MAXN-1;i>=1&&n;i--)
			if(n>=a[i])
			{
				k[i]=true;
				n-=a[i];
			}
		dp[l][0]=1;
		for(int i=0;i<MAXN;i++) 
			if(k[i]==true)
			{
				dp[i][0]=dp[l][0]+dp[l][1];
				dp[i][1]=(i-l-1)/2*dp[l][0]+(i-l)/2*dp[l][1];
				ans=dp[i][0]+dp[i][1],l=i;
			}
		cout<<ans<<'\n';
	}
}