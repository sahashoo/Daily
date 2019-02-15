///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
int n,m,door[maxn],col[maxn];
bool mrk[maxn];
vector<int>key[maxn];
vector<pair<int,int> >g[maxn];

void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>door[i];
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		for(int j=0;j<x;j++){
			int v;cin>>v;
			key[v].push_back(i);
		}
	}
}

void graphmaker(){
	for(int i=1;i<=n;i++){
		int u=key[i][0],v=key[i][1];
		g[u].push_back({v,door[i]});
		g[v].push_back({u,door[i]});
	}
	for(int i=0;i<maxn;i++)col[i]=-1;
}

bool BFS(){
	bool check=true;
	for(int i=1;i<=m;i++){
		if(mrk[i]==false&&g[i].size()){
			col[i]=0;mrk[i]=true;
			queue<int>Q;Q.push(i);
			while(Q.size()){
				int v=Q.front();Q.pop();
				for(auto u:g[v]){
					int color=col[v];
					if(u.S==0)color=1-color;
					if(mrk[u.F]&&col[u.F]!=color)check=false;
					if(mrk[u.F]==false){
						col[u.F]=color;
						mrk[u.F]=true;
						Q.push(u.F);
					}
				}
			}
		}
	}
	return check;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	graphmaker();
	if(BFS())cout<<"YES";
	else cout<<"NO";
}
