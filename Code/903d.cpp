#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
int a[MAXN];
long double sum[MAXN],res;
map<int,int>mp;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=a[i]+sum[i-1];
    for(int i=n-1;i>0;i--)
        res+=1.0*(sum[n]-sum[i]-(n-i)*a[i]);
    mp[a[n]]++;
    for(int i=n-1;i>0;i--)
        res=res-mp[a[i]+1]+mp[a[i]-1],
        mp[a[i]]++;
    cout<<fixed<<setprecision(0)<<res<<endl;
}