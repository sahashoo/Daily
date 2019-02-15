///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e3+9;
int w[MAXN],b[MAXN],par[MAXN],kol[MAXN],sum[MAXN],dp[MAXN];
vector<int>scc[MAXN];

int find(int x){return par[x]==x?x:find(par[x]);}

int32_t main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<MAXN;i++)par[i]=i;
	
	int n,m,W;cin>>n>>m>>W;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	
	for(int i=1,u,v;i<=m;i++)
		cin>>u>>v,par[find(u)]=find(v);
	
	for(int i=1,x;i<=n;i++)
		x=find(i),kol[x]+=w[i],sum[x]+=b[i],scc[x].push_back(i);
	
	for(int i=1;i<=n;i++)
		if(par[i]==i){
			for(int j=W;j>=0;j--){
				for(auto u:scc[i])
					if(j>=w[u])
						dp[j]=max(dp[j],dp[j-w[u]]+b[u]);
				if(j>=kol[i])
					dp[j]=max(dp[j],dp[j-kol[i]]+sum[i]);
			}
		}
	cout<<dp[W];
}