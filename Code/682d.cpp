///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+7;
int dp[N][N][11][2],n,m,k;
string s,t;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k>>s>>t;
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i-1]==t[j-1])
					dp[i][j][l][0]=1+max(dp[i-1][j-1][l-1][1],dp[i-1][j-1][l][0]);
				dp[i][j][l][1]=max(dp[i][j][l][0],max(dp[i-1][j][l][1],dp[i][j-1][l][1]));
			}
		}
	}
	cout<<dp[n][m][k][1];
}
