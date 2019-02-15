//for knowing the order if sequens we will get other arr and in each tile we we will add its par and like dsu read it
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int ans,dp[maxn],n;

int lis(){
	int it=0;
	for(int i=1;i<=n;i++)dp[i]=1;
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(arr[j]>=arr[i])dp[j]=max(dp[j],dp[i]+1);
		}
	}
	for(int i=0;i<=n;i++)ans=max(ans,dp[i]);
	return ans;
}

int LIS(int &a[],int n){
	fill(lst,lst+maxn,INF);
	int res=0;
	for(int i=0;i<n;i++){
		int j=lower_bound(lst,lst+n,a[i])-lst-1;
		dp[i]=j+1;
		lst[j+1]=min(lst[j+1],a[i]);
		res=max(res,dp[i]);
	}
	return res;
}

int32_t main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
	cout<<lis();
}
