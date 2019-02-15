#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+12;
const int modulo=1e9+7;
ll t,k,dp[MAXN],sum[MAXN],ans[MAXN];
int main(){
	cin>>t>>k;
    dp[0]=1;
    sum[0]=1;
	for(ll i=1;i<MAXN;i++){
        if(i>=k)dp[i]=(dp[i-k]+dp[i-1])%modulo;
		else dp[i]=(dp[i-1])%modulo;
        sum[i]=(sum[i-1]+dp[i])%modulo;
    }
	for(ll i=0;i<t;i++){
		ll a,b;
        cin>>a>>b;
        ans[i]=(sum[b]-sum[a-1]+modulo)%modulo;
	}
	for(ll i=0;i<t;i++)cout<<ans[i]<<endl;
}