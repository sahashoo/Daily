///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
void null(){return ;}
const int maxn=1e5+7;
const int lgN=20;
int n,m,cnt,d[maxn],bgn[maxn],trm[maxn],anc[maxn][lgN];
vector<int>g[maxn],h[maxn];

void dfs(int v){
	bgn[v]=cnt++;
	h[d[v]].push_back(bgn[v]);
	for(auto u:g[v]){
		d[u]=d[v]+1;
		anc[u][0]=v;
		for(int i=1;i<lgN;i++)
			anc[u][i]=anc[anc[u][i-1]][i-1];
		dfs(u);
	}
	trm[v]=cnt;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,a;i<=n;i++)cin>>a,g[a].push_back(i);
	dfs(0);
	cin>>m;
	while(m--){
		int v,p;cin>>v>>p;
		for(int i=0;i<lgN;i++)
			if(p&(1<<i))v=anc[v][i];
		if(v==0){cout<<"0 ";continue;}
		int r=upper_bound(h[d[v]+p].begin(),h[d[v]+p].end(),trm[v])-h[d[v]+p].begin();
		int l=upper_bound(h[d[v]+p].begin(),h[d[v]+p].end(),bgn[v])-h[d[v]+p].begin();
		cout<<r-l-1<<" ";
	}
}
