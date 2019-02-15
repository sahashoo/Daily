#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int ans,dp[maxn],lst[MAXN],n;

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
	cout<<LIS(arr,n);
}
