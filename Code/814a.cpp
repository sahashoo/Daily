#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,k,a[maxn],b[maxn];

int32_t main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)cin>>b[i];
    int li=1,nm=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){nm++;a[i]=b[1];}
    }
    if(nm>k)return cout<<"No"<<nm,0;
    if(k!=1)return cout<<"Yes",0;
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i-1])return cout<<"Yes",0;
    }
    cout<<"No";
}
