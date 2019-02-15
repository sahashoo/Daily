///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int N=4e3+7,M=1e6+7;
int a[N],bgn[M],cnt[M],dp[N][N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,cntmx=0,mx=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		cntmx=max(cntmx,cnt[a[i]]);
		bgn[a[i]]=(bgn[a[i]]==0?i:bgn[a[i]]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++){
			if(a[i]!=a[j])
				dp[bgn[a[j]]][bgn[a[i]]]=dp[bgn[a[i]]][bgn[a[j]]]+1;
			mx=max(mx,dp[bgn[a[j]]][bgn[a[i]]]);
		}
	cout<<max(cntmx,mx+1);
}