///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define ld long double
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=3e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn],dp[maxn][2];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	if(a[0])dp[0][0]=0,dp[0][1]=1;
	else dp[0][0]=dp[0][1]=0;
	
	for(int i=1;i<n;i++){
		if(a[i])dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1]+1;
		else dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]),dp[i][1]=dp[i-1][1];
	}
	
	cout<<n-dp[n-1][0];
}
