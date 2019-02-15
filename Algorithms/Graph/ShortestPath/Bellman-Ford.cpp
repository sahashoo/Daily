#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,m,s,dist[100007];
vector<pair<int,pair<int,int> > >edge;

void Bellman_Ford(){
	for(int i=1;i<=n;i++)dist[i]=INF;
	dist[s]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge.size();j++){
			int u=edge[j].second.second,v=edge[j].second.first;
			dist[v]=min(dist[u]+edge[j].first,dist[v]);
		}
	}
}

int main(){
	cin>>n>>m>>s;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		if(v<u)swap(u,v);
		edge.push_back(make_pair(w,make_pair(v,u)));
	}
	Bellman_Ford();
	for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
}