#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,m,c,d,cost[maxn],dough[maxn],best[maxn],dp[maxn];
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>c>>d;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b>>dough[i]>>cost[i];
        dp[i]=a/b;
    }
    for(int i=0;i+c<=n;i++)best[i+c]=max(best[i+c],best[i]+d);
    for(int i=0;i<m;i++){
		for(int j=n;j>=0;j--){
			for(int k=1;k<=dp[i]&&j-k*dough[i]>=0;k++){
				best[j]=max(best[j],best[j-k*dough[i]]+k*cost[i]);
			}
		}
	}
	cout<<best[n];
}
