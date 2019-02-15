#include<bits/stdc++.h>
#define int long long
#define bug cout<<endl<<endl<<"*/*/*/*/*/*/1232456"<<endl<<endl;
using namespace std;
const int maxn=1e5+7,INF=3e18+987654;
int n,m,scc[maxn],flg[maxn],age[maxn];
bool mrk[maxn],onstk[maxn];
vector<int>g[maxn];
stack<int>stk;

void input(){
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++)cin>>u>>v,g[u].push_back(v);
}

int cur_scc=1,cnt;
void dfs(int v){
	flg[v]=age[v]=++cnt;
	stk.push(v);
	onstk[v]=true;
	for(auto u:g[v]){
		if(flg[u]==0)dfs(u),age[v]=min(age[u],age[v]);
		else if(onstk[u])age[v]=min(age[u],age[v]);
	}
	if(flg[v]==age[v]){
		int stktop;
		do{
			stktop=stk.top();
			onstk[stk.top()]=false;
			scc[stk.top()]=cur_scc;
			stk.pop();
		}while(stktop!=v);
		cur_scc++;
	}
}

int32_t main(){
	input();
	for(int i=1;i<=n;i++){
		if(flg[i]==0){
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)cout<<"SCC "<<i<<" is :"<<scc[i]<<endl;
}
/*
	7 8
	1 2
	2 3
	3 4
	4 5
	5 6
	6 7
	6 2
	6 4
*/