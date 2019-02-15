#include<bits/stdc++.h>
#define q first
#define w second
using namespace std;
const int maxn=2e5+7;
int n,q,k,arr[maxn],d[maxn],ans[maxn];

int32_t main(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        arr[x]++;
        arr[y+1]--;
    }
    for(int i=1;i<maxn;i++){
        arr[i]+=arr[i-1];
        if(arr[i]>=k)d[i]++;
        d[i]+=d[i-1];
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        ans[i]=d[b]-d[a-1];
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<" ";
}
