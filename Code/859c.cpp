///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn],sum[maxn];
int dp[maxn][3];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int sum=0;
	for(int i=n-1;i>=0;i--){
		dp[i][0]=max(dp[i+1][0],sum-dp[i+1][1]+a[i]);
		dp[i][1]=max(dp[i+1][1],sum-dp[i+1][0]+a[i]);
		sum+=a[i];
	}
	// for(int i=0;i<n;i++)cout<<dp[i][0]<<" ";cout<<endl;
	// for(int i=0;i<n;i++)cout<<dp[i][1]<<" ";cout<<endl;
	cout<<sum-dp[0][0]<<" "<<dp[0][0];
}
