#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll dp[10000007],n;

int main(){
	cin>>n;
	dp[0]=1;
	dp[1]=0;
	dp[2]=3;
	for(ll i=2;i<=n;i++){
		dp[i]=(2*dp[i-1])+(3*dp[i-2]);
		dp[i]%=mod;
	}
	cout<<dp[n];
}