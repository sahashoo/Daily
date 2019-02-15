///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
bool mrk[MAXN];
int cntv,cnte;
vector<int>g[MAXN];

void dfs(int v){
	mrk[v]=true;
	cntv++;
	cnte+=g[v].size();
	for(auto u:g[v])
		if(mrk[u]==false)dfs(u);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
		cin>>u>>v,g[v].push_back(u),g[u].push_back(v);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(mrk[i]==false){
			cntv=cnte=0;
			dfs(i);
			cnt+=(cnte/2+(cnte&1)<cntv);
		}
	cout<<cnt;
}