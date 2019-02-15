#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,dp[2200][2200],ans;

int main(){
	cin>>n>>k;
	dp[0][1]=1;
	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=n;j++)
			for(ll o=j;o<=n;o+=j)(dp[i][o]+=dp[i-1][j])%=1000000007;
	for(ll i=1;i<=n;i++)(ans+=dp[k][i])%=1000000007;
	cout<<ans;
}