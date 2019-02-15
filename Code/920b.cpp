#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
pair<int,pair<int,int> >a[MAXN];
int ans[MAXN];

void solve(){
	int n;cin>>n;
	for(int i=0,x,y;i<n;i++)
		cin>>x>>y,a[i]={x,{i,y}};
	sort(a,a+n);
	int t=a[0].F;
	For(i,n){
		if(t<=a[i].S.S){
			t=max(t,a[i].F);
			ans[a[i].S.F]=t;
			t++;
		}
		else ans[a[i].S.F]=0;
	}
	For(i,n)cout<<ans[i]<<" ";cout<<'\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;cin>>q;
	while(q--)solve();
}
