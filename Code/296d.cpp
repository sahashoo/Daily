///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=500+7;
int n,dp[maxn][maxn],v[maxn];
long long sum[maxn];

inline void Floyd_Warshall(int u){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=min(dp[i][j],dp[i][v[u]]+dp[v[u]][j]);
	for(int i=u;i<=n;i++)
		for(int j=u;j<=n;j++)
			sum[u]+=dp[v[i]][v[j]];			
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dp[i][j];
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=n;i>0;i--)Floyd_Warshall(i);
	for(int i=1;i<=n;i++)cout<<sum[i]<<' ';
}