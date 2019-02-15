///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int dp[maxn],res,a[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];//,mrk[a[i]]=true;
	vector<int>div;
	for(int i=0;i<n;i++){
		int x=a[i];
		div.clear();dp[x]=1;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				dp[x]=max(dp[x],dp[i]+1);
				div.push_back(i);
			}
			if(i*i==x)continue;
			int j=x/i;
			if(x%j==0){
				dp[x]=max(dp[x],dp[j]+1);
				div.push_back(j);
			}
		}
		for(auto y:div)dp[y]=dp[x];
		res=max(res,dp[x]);
	}
	cout<<res;
}
