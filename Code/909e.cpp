///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF=1e9+9237;
const int MAXN=1e5+7;
int din[MAXN],ret;
bool col[MAXN],mrk[MAXN];
vector<int>g[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>col[i];
	for(int i=0,u,v;i<m;i++)
		cin>>u>>v,g[v].push_back(u),din[u]++;
	queue<int>Q[2];
	for(int i=0;i<n;i++)
		if(din[i]==0)Q[col[i]].push(i);
	while(Q[0].size()||Q[1].size()){
		while(Q[0].size()){
			int v=Q[0].front();Q[0].pop();
			for(int u:g[v]){
				din[u]--;
				if(din[u]==0)Q[col[u]].push(u);
			}
		}
		bool c=false;
		while(Q[1].size()){
			c=true;
			int v=Q[1].front();Q[1].pop();
			for(int u:g[v]){
				din[u]--;
				if(din[u]==0)Q[col[u]].push(u);
			}
		}
		ret+=c;
	}
	cout<<ret;
}
