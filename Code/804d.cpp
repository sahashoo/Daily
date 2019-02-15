#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int MAXN=1e5+7;
vector<int>g[MAXN],ccv[MAXN],prf[MAXN],cc[MAXN];
int id[MAXN],mxd[MAXN],sz[MAXN],rt[MAXN],diam[MAXN];
int temp_sz,ind,n;

void find_cc(int v,int p){
	id[v]=ind;
	temp_sz++;
	cc[ind].push_back(v);
	for(int u:g[v])
		if(u!=p)find_cc(u,v);
}
int mxh,dia_v,dia_u;
void find_dia_pre(int v,int p,int h){
	if(h>mxh)mxh=h,dia_v=v;
	for(int u:g[v])
		if(u!=p)find_dia_pre(u,v,h+1);
}

void find_dia_post(int v,int p,int h){
	if(h>mxh)mxh=h,dia_u=v;
	for(int u:g[v])
		if(u!=p)find_dia_post(u,v,h+1);
}

void max_dist_v(int v,int p,int h){
	mxd[v]=max(h,mxd[v]);
	for(int u:g[v])
		if(u!=p)max_dist_v(u,v,h+1);
}

void max_dist_u(int v,int p,int h){
	mxd[v]=max(h,mxd[v]);
	for(int u:g[v])
		if(u!=p)max_dist_u(u,v,h+1);
}

void precompute(){
	for(int i=1;i<=n;i++){
		if(id[i]==0){
			temp_sz=0;
			ind++;
			find_cc(i,-1);
			rt[ind]=i;
			sz[ind]=temp_sz;
		}
	}
	for(int i=1;i<=ind;i++){
		mxh=-1;find_dia_pre(rt[i],-1,0);
		mxh=-1;find_dia_post(dia_v,-1,0);
		max_dist_v(dia_v,-1,0);
		max_dist_u(dia_u,-1,0);
		diam[i]=mxd[dia_v];
		for(int u:cc[i])ccv[i].push_back(mxd[u]);
		sort(ccv[i].begin(),ccv[i].end());
		prf[i].resize(ccv[i].size()+1,0);
		for(int j=0;j<ccv[i].size();j++)
			prf[i][j+1]=prf[i][j]+ccv[i][j];
	}
}

map<pair<int,int>,ld>mp;
ld calc(int a,int b){
	if(a==b)return -1;
	if(sz[a]>sz[b])swap(a,b);
	pair<int,int>temp={a,b};
	if(mp.count(temp))return mp[temp];
	long long res=0,mx_dia=max(diam[a],diam[b]);
	for(int d:ccv[a]){
		int p=upper_bound(ccv[b].begin(),ccv[b].end(),mx_dia-d-1)-ccv[b].begin();
		res+=p*mx_dia;
		res+=prf[b][sz[b]]-prf[b][p];
		res+=1ll*((int)(sz[b])-p)*(d+1);
	}
	ld ret=(ld)res/(ld)(sz[b])/(ld)(sz[a]);
	mp[temp]=ret;
	return ret;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m,q;cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	precompute();
	cout<<setprecision(12)<<fixed;
	while(q--){
		int u,v;cin>>u>>v;
		cout<<calc(id[u],id[v])<<'\n';
	}
}