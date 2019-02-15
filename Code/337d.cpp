#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e18+7;
int n,m,d,res,h[maxn][2];
vector<int>g[maxn];
bool mrk[maxn];

void input(){
	cin>>n>>m>>d;
	for(int i=0;i<m;i++){int a;cin>>a;mrk[a]=true;}
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
}

void dfs(int v, int p){
	h[v][0]=-INF;h[v][1]=-INF;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i];
		if(u==p)continue;
		dfs(u,v);
		int hu=h[u][0]+1;
		if(hu>h[v][0])h[v][1]=h[v][0],h[v][0]=hu;
		else if(h[u][0]>h[v][1])h[v][1]=hu;
	}
	if(mrk[v]){
		if(h[v][0]<0)h[v][0]=0;
		if(h[v][1]<0)h[v][1]=0;
	}
}

void calc(int v, int p, int ft){
	if(max(h[v][0],ft)<=d)res++;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i];
		if(u==p)continue;
		if(h[v][0]==h[u][0]+1)calc(u,v,max(ft,h[v][1])+1);
		else calc(u,v,max(ft,h[v][0])+1);
	}
}

int32_t main(){
	input();
	dfs(1,0);
	calc(1,0,-INF);
	cout<<res;
}