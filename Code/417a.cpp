#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,d,n,m,k,nm,cd;cin>>c>>d>>n>>m>>k;
	nm=n*m-k;
	if(nm<=0)cout<<0;
	else cout<<min(min((nm/n)*c+(nm%n?c:0),(nm/n)*c+(nm%n)*d),nm*d);
}