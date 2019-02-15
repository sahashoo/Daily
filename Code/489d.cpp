///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXV=3001;
const int INF=1e9+7;
int h[MAXV][MAXV];
// bool mrk[MAXV][MAXV];
vector<int>g[MAXV];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0,u,v;i<m;i++)cin>>u>>v,g[u].push_back(v);
	int cnt=0;
	for(int v=1;v<=n;v++)
		for(auto u:g[v])for(auto x:g[u])
			if(x!=v)cnt+=h[v][x],h[v][x]++;
	cout<<cnt;
}
