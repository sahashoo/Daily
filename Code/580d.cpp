///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define ld long double
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int N=19,maxn=3e5+7,INF=3e18+9237,mod=1e9+7;
int dp[1<<N][N],a[N],g[N][N];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i],dp[1<<i][i]=a[i];
	for(int i=0,u,v,c;i<k;i++)cin>>u>>v>>c,g[u-1][v-1]=c;
	
	int bst=0;
	for(int msk=0;msk<(1<<n);msk++){
		for(int i=0;i<n;i++){
			if(msk&(1<<i)){
				for(int j=0;j<n;j++)
					if(!(msk&(1<<j)))
						dp[msk|(1<<j)][j]=max(dp[msk|(1<<j)][j],dp[msk][i]+g[i][j]+a[j]);
			}
		}	
		if(__builtin_popcount(msk)==m)for(int i=0;i<n;i++)bst=max(bst,dp[msk][i]);
	}
	
	cout<<bst;
}
