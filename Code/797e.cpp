///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mxn=1e5+7;
int n,dp[320][mxn],a[mxn],q;
vector<int>ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>q;
	int sqr=sqrt(n);
	for(int i=1;i<=sqr;i++){
		for(int j=n;j>=0;j--){
			if(i+j+a[j]>n)dp[i][j]=1;
			else dp[i][j]=dp[i][i+j+a[j]]+1;
		}
	}
	while(q--){
		int p,k,cnt=0;cin>>p>>k;
		if(k<=sqr){ans.push_back(dp[k][p]);continue;}
		while(p<=n)cnt++,p+=a[p]+k;
		ans.push_back(cnt);
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}
