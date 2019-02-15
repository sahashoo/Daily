///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int res,n,m,F[maxn],G[maxn],H[maxn];
vector<int>g[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>F[i];
		g[F[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()==0)continue;
		res++;
		for(auto u:g[i])G[u]=res;
		H[res]=i;
	}
	for(int i=1;i<=n;i++)if(H[G[i]]!=F[i])return cout<<-1,0;
	for(int i=1;i<=res;i++)if(G[H[i]]!=i) return cout<<-1,0;
	cout<<res<<endl;
	for(int i=1;i<=n;i++)cout<<G[i]<<" ";
	cout<<endl;
	for(int i=1;i<=res;i++)cout<<H[i]<<" ";
	
}