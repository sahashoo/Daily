#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int dp[N],res;

int32_t main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		dp[++a]=i;
		int tmp=min(max(dp[a-2],dp[a+1]),max(dp[a-1],dp[a+2]));
		res=max(res,i-tmp);
	}
	cout<<res;
}