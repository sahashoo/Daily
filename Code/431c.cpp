#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=150,mod=1e9+7;
int dp[N][5];

int32_t main(){
	int n,k,d;cin>>n>>k>>d;
	dp[0][0]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i<j)break;
			if(j<d){
				dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;
				dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;
				if(dp[i][0]<0)dp[i][0]+=mod;
				if(dp[i][1]<0)dp[i][1]+=mod;
			}
			else{
				dp[i][1]=(dp[i][1]+dp[i-j][0]+dp[i-j][1])%mod;
				if(dp[i][1]<0)dp[i][1]+=mod;
			}
		}
	}
	cout<<dp[n][1];
}