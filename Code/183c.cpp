///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
inline int pls(int a,int b){return ((a+1)%b);}
inline int mns(int a,int b){return ((a+b-1)%b);}
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+5365;
int n,col[MAXN],cycle=-INF,flg[MAXN];
vector<int>g[MAXN],rg[MAXN];
bool mrk[MAXN],ret;

void dfs1(int v,int c){
	flg[v]=1;
	col[v]=c;
	for(int u:g[v])
		if(flg[u]==0)dfs1(u,c+1);
		else if(flg[u]==1&&abs(c-col[u]+1))
			cycle=abs(c-col[u]+1);
	for(int u:rg[v])
		if(flg[u]==0)dfs1(u,c-1);
		else if(flg[u]==1&&abs(c-col[u]-1))
			cycle=abs(c-col[u]-1);
	flg[v]=2;
}

bool dfs2(int v,int c,int k){
	mrk[v]=true;
	col[v]=c;
	for(int u:g[v])
		if(mrk[u]==false)dfs2(u,(c+1)%k,k);
		else if(col[u]!=(c+1)%k)return false;
	for(int u:rg[v])
		if(mrk[u]==false)dfs2(u,(c+k-1)%k,k);
		else if(col[u]!=(c+k-1)%k)return false;
    return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
    for(int i=1;i<=n;i++)
		if(mrk[i]==false)dfs1(i,1);
	if(cycle==-INF)return cout<<n,0;
	for(int i=cycle;i>0;i--){
		if(cycle%i==0){
			memset(col,0,sizeof(col));
			memset(mrk,0,sizeof(mrk));
			ret=true;
			for(int j=1;j<=n;j++)
				if(mrk[j]==false)ret&=dfs2(j,0,i);
			if(ret)return cout<<i,0;
		}
	}
}