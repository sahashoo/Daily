///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e3+7;
int dp[50][N],hlp[50][N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<N;i++)
		dp[0][i]=1,hlp[0][i]=i+1;
	for(int i=1;i<45;i++)
		for(int j=i;j<N;j++)
			dp[i][j]=(dp[i][j-i]+i*hlp[i-1][j-i])%mod,
			hlp[i][j]=(hlp[i][j-1]+dp[i][j])%mod;
	int t,n,k;cin>>t;
	while(t--)cin>>n>>k,cout<<(k<45?dp[k][n]:0)<<'\n';
}