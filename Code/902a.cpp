#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
vector<int>g[MAXN];
int m;
bool mrk[MAXN];

bool dfs(int v){
	if(v==m)return true;
	mrk[v]=true;
	for(auto u:g[v])
		if(mrk[u]==false)
			if(dfs(u))return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		for(int j=a+1;j<=b;j++)
			g[a].push_back(j);
	}
	if(dfs(0))cout<<"YES";
	else cout<<"NO";
}
