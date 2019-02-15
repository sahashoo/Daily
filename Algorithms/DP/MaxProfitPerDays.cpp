#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int k,n,ans,dp[maxn][maxn],prof[maxn];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>prof[i];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int m=1;m<j;m++){
				dp[i][j]=max(dp[i][j-1],dp[i-1][m]+prof[m]-prof[j]);
			}
		}
	}
}