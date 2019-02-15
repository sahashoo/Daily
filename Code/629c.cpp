#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2000+7,mod=1e9+7;
int dp[maxn][maxn][2],n,m,mn,cur;
string s;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<m;i++){
		if(s[i]=='(')cur++;
		else cur--;
		mn=min(mn,cur);
	}
	dp[0][0][0]=1;
	for(int i=0;i<=n-m;i++){
		for(int k=0;k<2;k++){
			for(int j=0;j<=n-m;j++){
				if(j<n-m)dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k])%mod;
				if(j>0)dp[i+1][j-1][k]=(dp[i+1][j-1][k]+dp[i][j][k])%mod;
				if(k==0&&j+mn>=0&&j+cur>=0&&j+cur<=n-m-i)dp[i][j+cur][1]=(dp[i][j+cur][1]+dp[i][j][k])%mod;
			}
		}
	}
	cout<<dp[n-m][0][1];
}
