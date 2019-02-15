///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn],cnt[maxn],d[maxn];
vector<pair<int,int> >g[maxn];

void dfs(int v,int k,int p){
	cnt[v]=k;
	if(a[v]<d[v])cnt[v]=0;
	for(auto u:g[v])if(u.F!=p)d[u.F]=max(0LL,d[v]+u.S),dfs(u.F,cnt[v],v);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1,p,c;i<n;i++)cin>>p>>c,g[i].pb({p-1,c}),g[p-1].pb({i,c});
	dfs(0,1,-1);
	int ans=0;
	for(int i=0;i<n;i++)ans+=!cnt[i];
	cout<<ans;
}