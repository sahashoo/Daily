///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+7,INF=1e18+7;
int dp[maxn],n,x,y;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>x>>y;
	dp[1]=x;
	for(int i=2;i<maxn;i++){
		if(i&1)dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+y+x);
		else dp[i]=min(dp[i-1]+x,dp[i/2]+y);
	}
	cout<<dp[n];
}
