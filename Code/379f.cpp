///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
// #define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int maxn=1e6+7;
// const int INF=3e18+9237;
const int mod=1e9+7;
const int LG=22;
int anc[maxn][LG],h[maxn];

int LCA(int u,int v){
	if(h[u]>h[v])swap(u,v);
	int depth=h[v]-h[u];
	for(int i=0;i<LG;i++)
		if(depth&(1<<i))v=anc[v][i];
	if(v==u)return v;
	for(int i=LG-1;i>=0;i--)
		if(anc[v][i]!=anc[u][i])
			v=anc[v][i],u=anc[u][i];
	return(u==v?v:anc[v][0]);
}

int dist(int u,int v){
	return h[u]+h[v]-2*h[LCA(u,v)];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	h[1]=0;
	h[2]=h[3]=h[4]=1;
	anc[2][0]=anc[3][0]=anc[4][0]=1;
	int q,v,bgn=2,trm=4,dim=2,n=4;
	cin>>q;
	vector<int>ans;
	while(q--){
		cin>>v;
		h[n+1]=h[n+2]=h[v]+1;
		anc[n+1][0]=anc[n+2][0]=v;
		for(int i=1;i<LG;i++){
			anc[n+1][i]=anc[anc[n+1][i-1]][i-1];
			anc[n+2][i]=anc[anc[n+2][i-1]][i-1];
		}
		if(dist(trm,n+1)>dim)dim++,bgn=n+1;
		else if(dist(bgn,n+1)>dim)dim++,trm=n+1;
		cout<<dim<<'\n';
		n+=2;
	}
}
