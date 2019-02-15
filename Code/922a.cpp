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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y;cin>>x>>y;
	if(y==0||(y==1&&x!=0))cout<<"No";
	else if(x>=y-1&&x%2!=y%2)cout<<"Yes";
	else cout<<"No";
}
