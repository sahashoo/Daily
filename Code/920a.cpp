#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define For(i,n)  for(ll i=0;i<n;i++)
#define Forr(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORR(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int dp[MAXN];

void solve(){

	memset(dp,63,sizeof dp );

	int n,k,ans=-1;cin>>n>>k;

	for(int j=0;j<k;j++){
		int x;cin>>x;
		for(int i=1;i<=n;i++)
			dp[i]=min(dp[i],abs(i-x)+1);
	}

	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);

	cout<<ans<<'\n';

}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
