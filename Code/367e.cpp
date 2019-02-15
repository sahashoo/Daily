///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=350;
const int mod=1e9+7;
int dp[N][N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,x;cin>>n>>m>>x;
	if(n>m)return cout<<0,0;
	dp[0][0]=1;
	for(int i=1;i<=m;i++){
		int l=min(i,n);
		for(int j=l;j>=0;j--)
			for(int k=l-j;k>=0;k--)
				if(dp[j][k]){
					dp[j+1][k]=(dp[j+1][k]+dp[j][k])%mod;
					dp[j][k+1]=(dp[j][k+1]+dp[j][k])%mod;
					if(i==x)dp[j][k]=0;
					else if(k)dp[j+1][k-1]=(dp[j+1][k-1]+dp[j][k])%mod;
				}
	}
	for(int i=1;i<=n;i++)dp[n][0]=(dp[n][0]*i)%mod;
	cout<<dp[n][0];
}
