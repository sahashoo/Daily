#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e3+7;
int n,k,a[MAXN],dp[MAXN];

bool check(int val){
	fill(dp,dp+n,2e9+7);
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i]=i;
		for(int j=0;j<i;j++)
			if((abs(a[i]-a[j])+(i-j)-1)/(i-j)<=val)
				dp[i]=min(dp[i],dp[j]+i-j-1);
	}
	int mn=2e9+7;
	for(int i=0;i<n;i++)
		mn=min(mn,dp[i]+n-i-1);
	return (mn<=k);
}

int32_t main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l=-1,r=2e9+7;
	while(r-l>1)
		(check(l+r>>1)?r:l)=l+r>>1;
	cout<<r<<endl;
}