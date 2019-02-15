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
const int INF=1e6;
const int MAXN=500*1000;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,ans=0;cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a>MAXN)ans=max(INF-a,ans);
		else ans=max(a-1,ans);
	}
	cout<<ans;
}
