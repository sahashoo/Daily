///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+7,INF=1e18+7;
int a[MAXN],b[MAXN],dp[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k=0,res=INF;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)dp[i]=abs(a[0]-b[i]);
	for(int i=1;i<n;i++){
		res=INF;
		for(int j=0;j<n;j++)
			res=min(res,dp[j]),
			dp[j]=res+abs(a[i]-b[j]);
	}
	res=INF;
	for(int i=0;i<n;i++)res=min(res,dp[i]);
	cout<<res;
}
