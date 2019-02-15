///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int N=19,maxn=3e5+7,INF=3e18+9237,mod=1e9+7;
ld dp[1<<N][N],p[N][N];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>p[i][j];
	
	dp[1][0]=1.0;
	for(int msk=2;msk<(1<<n);msk++){
		for(int i=0;i<n;i++){
			if(msk&(1<<i)){
				dp[msk][i]=0.0;
				for(int j=0;j<n;j++){
					if((msk&(1<<j))&&j!=i)
						dp[msk][i]=max(dp[msk][i],p[i][j]*dp[msk^(1<<j)][i]+p[j][i]*dp[msk^(1<<i)][j]);
				}
			}
		}
	}
	
	ld res=0.0;
	for(int i=0;i<n;i++)res=max(res,dp[(1<<n)-1][i]);
	cout<<fixed<<setprecision(12)<<res;
}