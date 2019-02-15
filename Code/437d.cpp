///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define ld long double
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,m,a[maxn],par[maxn],siz[maxn];
pair<int,pair<int,int> >g[maxn];

bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){return a>b?true:false;}

int getpar(int x){return(x==par[x]?x:par[x]=getpar(par[x]));}

ld Merg(int u,int v){
	u=getpar(u);v=getpar(v);
	if(v==u)return 0;
	ld res=(ld)siz[u]*siz[v];
	if(siz[u]>=siz[v])siz[u]+=siz[v],par[v]=u;
	else siz[v]+=siz[u],par[u]=v;
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		par[i]=i;siz[i]=1;
	}
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[i]={min(a[u],a[v]),{u,v}};
	}
	sort(g,g+m,cmp);
	ld res=0;
	for(auto E:g)res+=(ld)E.F*Merg(E.S.F,E.S.S);
	res/=(ld)n*(n-1)/2;
	cout<<fixed<<setprecision(12)<<res;
}
