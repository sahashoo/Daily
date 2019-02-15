#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5012;
ll dp[maxn][maxn],cp[maxn],ans;
int n,m,k,arr[maxn];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=1;i<=k;i++){
		dp[m*i][i]+=dp[m*(i-1)][i-1];
		for(ll j=((i-1)*m)+1;j<=(i*m);j++){
			dp[m*i][i]+=arr[j];
			cp[m*i]+=arr[j];
			if(i==k)ans=max(ans,dp[m*k][k]);
		}
		
	}
	for(int i=1;i<=k;i++){
	    for(ll j=(i*m)+1;j<=n;j++){
            cp[j]=cp[j-1]+arr[j]-arr[j-m];
            dp[j][i]=max(dp[j-1][i],cp[j]+dp[j-m][i-1]);
			if(i==k)ans=max(ans,dp[j][k]);
        }
    }
	cout<<ans<<endl;


}
