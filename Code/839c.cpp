#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define ld long double
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int n,h[maxn],avr,cnt;
vector<int>g[maxn],lf;
bool mrk[maxn];
ld val[maxn];

void dfs(int v,int H,ld vl){
	h[v]=H;
	val[v]=vl;
	mrk[v]=true;
	if(g[v].size()==1&&H)return lf.push_back(v);
	int sz=g[v].size();
	if(H)sz--;
	long double dd=(ld)vl/sz;
	for(auto u:g[v])if(mrk[u]==false)dfs(u,H+1,dd);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,1);
	long double ans=0;
	//for(int i=1;i<=n;i++)cout<<g[i].size()<<endl;
	for(auto x:lf)ans+=(long double)val[x]*h[x];
	cout<<fixed<<setprecision(12)<<ans;
}