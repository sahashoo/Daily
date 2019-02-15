///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int n,dist[maxn],mx,ans;
vector<pair<int,int> >g[maxn];

void input(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		ans+=w*2;
	}
}

void dijkstra(){
	priority_queue<pair<int,int> >Q;Q.push({0,1});
	for(int i=0;i<maxn;i++)dist[i]=INF;dist[1]=0;
	while(Q.size()){
		int v=Q.top().S,d=Q.top().F;Q.pop();
		if(d!=dist[v])continue;
		for(auto u:g[v]){
			if(u.S+dist[v]<dist[u.F]){
				dist[u.F]=u.S+dist[v];
				Q.push({dist[u.F],u.F});
			}
		}
	}
	for(int i=2;i<=n;i++)mx=max(mx,dist[i]);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	dijkstra();
	cout<<ans-mx;
}
