///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[maxn],dp[maxn],lst[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	fill(lst,lst+maxn,INF);
	int res=0;
	for(int i=0;i<n;i++){
		int j=lower_bound(lst,lst+n,a[i])-lst-1;
		dp[i]=j+1;
		lst[j+1]=min(lst[j+1],a[i]);
		res=max(res,dp[i]);
	}
	cout<<res+1;
}
