#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e6+7;
int n,ans,v[maxn],vs[maxn],si;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[a]++;
        for(int j=a;j<maxn;j+=a)v[j]=max(v[j],v[a]);
        ans=max(ans,v[a]);
    }
    cout<<ans;
}
