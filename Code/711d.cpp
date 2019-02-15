///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
inline void VOID(){return;}
const int mod=1e9+7;
const int MAXN=2e5+7;
int mrk[MAXN],g[MAXN];
long long tw[MAXN];
vector<int>c;

void findlen(int v){
	c.back()++;
	mrk[v]=3;
	if(mrk[g[v]]==3)return ;
	findlen(g[v]);
}

void dfs(int v){
	mrk[v]=2;
	if(mrk[g[v]]==0)dfs(g[v]);
	else if(mrk[g[v]]==1)return mrk[v]=1,VOID();
	else c.push_back(0),findlen(v);
	mrk[v]=1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	tw[0]=1;
	for(int i=1;i<MAXN;i++)tw[i]=(2ll*tw[i-1])%mod;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>g[i];
	for(int v=1;v<=n;v++)
		if(mrk[v]==0)dfs(v);
	long long res=1;
	for(auto x:c)
		n-=x,res=(res*(tw[x]-2))%mod;
	res=(res*tw[n])%mod;
	cout<<res;
}
