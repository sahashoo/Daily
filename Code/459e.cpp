///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=3e5+7;
int dp[maxn],res[maxn];
vector<pair<int,int> >E[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		E[w].push_back({u,v});
	}
	for(int i=0;i<maxn;i++){
		for(auto e:E[i])res[e.S]=0;
		for(auto e:E[i])res[e.S]=max(res[e.S],dp[e.F]+1);
		for(auto e:E[i])dp[e.S]=max(res[e.S],dp[e.S]);	
	}
	cout<<*max_element(dp+1,dp+n+1);
}
