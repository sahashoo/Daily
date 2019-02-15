#include<bits/stdc++.h>
using namespace std;
const int MAXN=8e6+7;
const int lg=23;
int a[MAXN],dp[MAXN];

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp,-1,sizeof dp);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		dp[a[i]]=a[i];
	}
	
	vector<int>vec[lg+1];
	for(int i=0;i<MAXN;i++)
	{
		int j=0,k=i;
		while(k)
		{
			j++;
			k-=k&(-k);
		}
		vec[j].push_back(i);
	}
	for(int i=0;i<lg;i++)
		for(int j:vec[i])
			for(int k=0;k<lg;k++)
			{
				if((j>>k&1)&&dp[(j^(1<<k))]!=-1)	
				{
					dp[j]=dp[(j^(1<<k))];
					break;
				}
			}
				
	for(int i=0;i<n;i++)
		cout<<dp[( (~a[i]) & ((1<<(lg-1))-1) )]<<" ";
}
