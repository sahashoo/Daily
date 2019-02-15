#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,s,a[maxn],b[maxn];

int check(int k){
    for(int i=0;i<n;i++)b[i]=a[i]+(i+1)*k;
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<k;i++)ans+=b[i];
    return ans;
}

int32_t main(){
    cin>>n>>s;
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=n+1;
    while(l<r-1){
        int m=(l+r)/2;
        if(check(m)<=s)l=m;
        else r=m;
    }
    cout<<l<<" "<<check(l)<<endl;
}
