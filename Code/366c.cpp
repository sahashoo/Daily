#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=(int)1e5;
int n,k,a[100],b[100],dp[107][2*maxn];

int32_t main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    memset(dp,-1,sizeof(dp));
    dp[0][maxn]=0;
    dp[0][a[0]-(k*b[0])+maxn]=a[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<=2*maxn;j++){
            if(dp[i][j]!=-1){
				dp[i+1][j+a[i+1]-(k*b[i+1])]=max(dp[i+1][j+a[i+1]-(k*b[i+1])],dp[i][j]+a[i+1]);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			}
        }
    }
    if(dp[n][maxn]==0)cout<<-1;
    else cout<<dp[n][maxn];
}