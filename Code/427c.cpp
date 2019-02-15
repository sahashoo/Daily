///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int mod=1e9+7;
const int INF=2e9+7;
int mn,cnt,cst[maxn];
bool mrk[maxn];
vector<int>g[maxn],rg[maxn],tps;

void topo(int v){
	mrk[v]=true;
	for(auto u:g[v])
		if(mrk[u]==false)topo(u);
	tps.push_back(v);
}

void scc(int v){
	mrk[v]=false;
	if(mn>cst[v])mn=cst[v],cnt=1;
	else if(mn==cst[v])cnt++;
	for(auto u:rg[v])
		if(mrk[u])scc(u);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,s;cin>>n;
	for(int i=1;i<=n;i++)cin>>cst[i];
	cin>>m;
	for(int i=0,u,v;i<m;i++)
		cin>>u>>v,g[u].push_back(v),rg[v].push_back(u);
	for(int i=1;i<=n;i++)
		if(mrk[i]==false)topo(i);
	reverse(tps.begin(),tps.end());
	long long prc=0,res=1;
	for(auto i:tps)
		if(mrk[i]){
			mn=INF,cnt=0;
			scc(i);
			res=(res*cnt)%mod;
			prc+=mn;
		}
	cout<<prc<<" "<<res<<endl;
}