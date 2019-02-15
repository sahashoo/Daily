#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3007;
int a[maxn],b[maxn],c[maxn],dp[maxn],dp2[maxn],n;

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    dp[0]=a[0];
    dp2[0]=b[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp2[i-1]+a[i],dp[i-1]+b[i]);
        dp2[i]=max(dp2[i-1]+b[i],dp[i-1]+c[i]);
    }
    cout<<dp[n-1];
}
