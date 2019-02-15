//chernobil
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int egg,n,dp[maxn][maxn];

int eggdropp(){
	for(int i=1;i<=egg;i++)for(int j=1;j<=n;j++)dp[i][j]=maxn;
	for(int i=1;i<=n;i++)dp[1][i]=i;
	for(int i=2;i<=egg;i++){
		for(int j=1;j<=n;j++){
			if(j>i)dp[i][j]=dp[i-1][j-1];
			else for(int k=1;k<=j;k++){
				dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i-1][j-k]));
			}
		}
	}
	return dp[egg][n];
}

int main(){
	cin>>n>>egg;
	cout<<eggdropp()<<endl;
	for(int i=0;i<=egg;i++){for(int j=0;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;}
}