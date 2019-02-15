#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=4e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=22;
int par[lgN][MAXN],sum[lgN][MAXN],w[MAXN],lst=0,cur=1;

int add(int p,int W){
	cur++;
	w[cur]=W;
	if(w[p]>=w[cur]){
		par[0][cur]=p;
	}
	else{
		int from=p;
		for(int i=19;i>=0;i--){
			if(w[par[i][from]]<w[cur])
				from=par[i][from];
		}
		par[0][cur]=par[0][from];
	}
	sum[0][cur]=(par[0][cur]==0?INF:w[par[0][cur]]);
	for(int i=1;i<lgN;i++){
		par[i][cur]=par[i-1][par[i-1][cur]];
		sum[i][cur]=(par[i][cur]==0?INF:sum[i-1][cur]+sum[i-1][par[i-1][cur]]);
	}
}

int query(int v,int W){
	if(w[v]>W){
		return 0;
	}
	W-=w[v];
	int ret=1;
	for(int i=19;i>=0;i--){
        if(sum[i][v]<=W){
            ret+=(1<<i);
            W-=sum[i][v];
            v =par[i][v];
        }
    }
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	w[0]=INF;
	for(int i=0;i<lgN;i++)sum[i][1]=INF;
	int tq;cin>>tq;
	while(tq--){
		int tp,p,q;
		cin>>tp>>p>>q;
		if(tp==1){
			add(p^lst,q^lst);
		}
		else{
			lst=query(p^lst,q^lst);
			cout<<lst<<'\n';
		}
	}
}
