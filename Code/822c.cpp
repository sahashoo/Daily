#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=2e5+7;
const int INF=1e16+7;
int n,x,ans=INF,l[maxn],r[maxn],c[maxn],dp[maxn];
vector<pair<int,pair<int,int> > >a;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i]>>c[i];
        a.push_back(make_pair(l[i],make_pair(0,i)));
        a.push_back(make_pair(r[i],make_pair(1,i)));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<maxn;i++)dp[i]=INF;
    for(int i=0;i<a.size();i++){
        int id=a[i].w.w;int d=r[id]-l[id]+1;
        if(a[i].w.q==1)  dp[d]=min(dp[d],c[id]);
        else if(d<x)ans=min(ans,dp[x-d]+c[id]);
    }
    if(ans<INF)cout<<ans;
    else cout<<-1;
}
