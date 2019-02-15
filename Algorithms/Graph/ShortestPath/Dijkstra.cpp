#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,m,dist[maxn];
bool mrk[maxn];
vector<pair<int,int> >g[maxn];

void input(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[v].push_back({u,w});
		g[u].push_back({v,w});
	}
}
 
void dijkstra(int start){
	memset(dist,63,sizeof(dist));
	dist[start]=0;//dist start=0
	priority_queue<pair<int,int> >Q;
	Q.push({start,0});
	while(Q.size()){
		pair<int,int> v=Q.top();Q.pop();
		//if(v.S>dist[v.F])continue;
		for(auto u:g[v.F])
			if(dist[u.F]>dist[v.F]+u.S)
				dist[u.F]=dist[v.F]+u.S,Q.push({u.F,dist[u.F]});
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	dijkstra(1);
	for(int i=2;i<=n;i++)cout<<"dist "<<i<<" is : "<<dist[i]<<'\n';
}