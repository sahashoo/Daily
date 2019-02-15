#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
const int maxn=22e5,INF=5e18+7;
int dp[maxn];
pair<int,pair<int,int> >a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
	fill(dp,dp+maxn,INF);
	dp[0]=0;
	int n,m,b;cin>>n>>m>>b;
	int tot=(1<<m);
	for(int i=0;i<n;i++){
		int x,k,t,q;cin>>x>>k>>t;
		int tmp=0;
		for(int i=0;i<t;i++)cin>>q,tmp+=1<<(q-1);
		a[i]={k,{x,tmp}};
	}
	sort(a,a+n);
	int mn=INF;
	for(int i=0;i<n;i++){
		for(int j=0;j<tot;j++){
			dp[j]=min(dp[j],dp[j&(j^a[i].S.S)]+a[i].S.F);
		}
		mn=min(mn,dp[tot-1]+a[i].F*b);
	}
	cout<<(mn==INF?-1:mn);
}