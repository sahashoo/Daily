#include<bits/stdc++.h>
#define ld long double
using namespace std;
ld dp[2007][2007];

int main(){
	ld n,p,t;cin>>n>>p>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			dp[i][j]=(ld)((ld)1-p)*dp[i][j-1];
			dp[i][j]+=(ld)p*(dp[i-1][j-1]+1);
		}
	}
	cout<<fixed<<setprecision(12)<<dp[(int)n][(int)t];
}