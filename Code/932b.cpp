#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e6+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int dp[MAXN][11];

int f(int x){
	int ret=1;
	while(x){
		if(x%10)ret*=x%10;
		x/=10;
	}
	return ret;
}

int g(int x){
	while(x>=10)
		x=f(x);
	return x;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for(int i=1;i<MAXN;i++){
		int x=g(i);
		for(int j=1;j<=9;j++)
			dp[i][j]=dp[i-1][j]+(x==j);
	}
	
	int q;cin>>q;
	while(q--){
		int l,r,k;cin>>l>>r>>k;
		cout<<dp[r][k]-dp[l-1][k]<<'\n';
	}
}
