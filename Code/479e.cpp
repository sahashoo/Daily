///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+7;
const int mod=1e9+7;
int dp[MAXN],sum[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a,b,k;cin>>n>>a>>b>>k;
	dp[a]=1;
	for(int i=0;i<k;i++){
		for(int j=1;j<=n+1;j++)
			sum[j]=(sum[j-1]+dp[j-1])%mod;
		for(int j=1;j<=n;j++){
			int l=(b<=j?((b+j)/2)+1:1);
			int r=(b>=j?((b+j+1)/2)-1:n);
			dp[j]*=-1;dp[j]+=mod;dp[j]%=mod;
			dp[j]+=(sum[r+1]-sum[l])%mod + mod;dp[j]%=mod;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res=(res+dp[i])%mod;
	cout<<res;
}