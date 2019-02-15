#include<bits/stdc++.h>
using namespace std;
const int N=110,mod=1e8;
int dp[N][N][2];

int32_t main(){
	int n1,n2,k1,k2;cin>>n1>>n2>>k1>>k2;
	dp[0][0][0]=dp[0][0][1]=1;
	
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			int lmi=min(k1,i),lmj=min(k2,j);
			for(int k=1;k<=lmi;k++)
				dp[i][j][0]=(dp[i-k][j][1]+dp[i][j][0])%mod;
			for(int k=1;k<=lmj;k++)
				dp[i][j][1]=(dp[i][j-k][0]+dp[i][j][1])%mod;
		}
	}
	cout<<(dp[n1][n2][0]+dp[n1][n2][1])%mod;
}