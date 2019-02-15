///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
const int sqN=320;
int n,nxt[MAXN],cnt[MAXN],par[MAXN];

inline void calc(int i){
	if(par[i]>=n||i/sqN!=par[i]/sqN)nxt[i]=i,cnt[i]=0;
	else nxt[i]=nxt[par[i]],cnt[i]=cnt[par[i]]+1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>par[i],par[i]+=i;
	for(int i=n;i>0;i--)calc(i);
	int type,node,val;
	while(m--){
		cin>>type>>node;
		if(type){
			int tmp=0,res=0;
			for(;node<=n;tmp=nxt[node],node=par[tmp])
				res+=cnt[node]+1;
			cout<<tmp<<" "<<res<<'\n';
		}
		else{
			cin>>val;
			par[node]=val+node;
			for(int i=node;i>0&&i/sqN==node/sqN;i--)
				calc(i);
		}
	}
}
