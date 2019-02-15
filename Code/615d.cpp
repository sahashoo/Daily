#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,m,ans;
map<int,int> ma;

int exp(int a,int q) {
    a%=INF;
    if(q==0)return 1;
    return ((q%2==1?a:1)*exp(a*a,q/2))%INF;
}

int32_t main(){
    cin>>m;
    for(int i=1;i<=m;i++){
        int a;cin>>a;
        ma[a]++;
    }
    int d=1,ans=1;
    for(auto x : ma){
        int cnt=x.w,p=x.q;
        int fp=exp(p,(cnt+1)*cnt/2);
        ans=(exp(ans,cnt+1)*exp(fp,d))%INF;
        d=d*(cnt+1)%(INF-1);
    }
    cout<<ans;
}
