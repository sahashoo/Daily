#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
const int INF=1e9+7;
int n,m,a[maxn],maxa[maxn],nxt[maxn],ans[maxn],ansp;

int add(int p,int x){
    a[p]+=x;
    if(a[p]>maxa[p]){
        nxt[p]=add(nxt[p],a[p]-maxa[p]);
        a[p]=maxa[p];
        return nxt[p];
    }
    else return p;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>maxa[i];
        nxt[i]=i+1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int q;cin>>q;
        if(q==1){
            int p,x;cin>>p>>x;
            add(p,x);
        }
        else{int p;cin>>p;ans[ansp++]=a[p];}
    }
    for(int i=0;i<ansp;i++)cout<<ans[i]<<endl;
}
