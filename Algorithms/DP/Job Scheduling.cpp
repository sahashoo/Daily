//job scheduling 
#include<bits/stdc++.h>
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,dp[maxn];
pair<int,pair<int,int> >job[maxn];

int js(){
	int ans=0;
	sort(job+1,job+n+1);
	for(int i=1;i<=n;i++)dp[i]=job[i].w.w;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(job[i].q>=job[j].w.q||job[j].q<=job[i].w.q)dp[i]=max(dp[i],dp[j]+job[i].w.w);
			ans=max(ans,dp[i]);
		}
	}
	return ans;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r,val;
		cin>>l>>r>>val;
		job[i].q=r;
		job[i].w.q=l;
		job[i].w.w=val;
	}
	cout<<js()<<endl;
	for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
}