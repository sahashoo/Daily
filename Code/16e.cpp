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
ld a[N][N],dp[(1<<N)];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	
	dp[(1<<n)-1]=1;
	
	for(int msk=(1<<n)-1;msk>=0;msk--){
		int cnt=0;
		for(int i=0;i<n;i++)if(msk&(1<<i))cnt++;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((msk&(1<<i))&&(msk&(1<<j))&&msk-i){
					dp[msk-(1<<j)]+=dp[msk]*a[i][j]*((ld)(1.0/((ld)(cnt*(cnt-1)/2))));
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)cout<<fixed<<setprecision(12)<<dp[1<<i]<<" ";
}
