///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
vector<int>g[maxn];
int w,b;

int pw(int a,int b){
	return (b==0?1:pw(a*a,b/2)*(b%2?a:1));
}

void dfs(int v,int p,int h){
	if(h%2==0)w++;
	else b++;
	for(auto u:g[v]){
		if(u!=p)dfs(u,v,h+1);
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int start=INF;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
		start=min(min(u,v),start);
	}
	dfs(start,-1,0);
	//cout<<w<<" "<<b<<" ";
	cout<<(b*w)-n+1;
}
