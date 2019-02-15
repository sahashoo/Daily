///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,MXLg=22;
int n,a[maxn],sgmnt[maxn*3][MXLg],lzy[maxn*3][MXLg],sm;

void build(int v=1,int l=1,int r=n){
	if (l==r){
		for(int i=0;i<=20;i++)if(a[l]&(1<<i))sgmnt[v][i]++;
		return ;
    }
	int mid=l+r>>1;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	for(int i=0;i<=20;i++)sgmnt[v][i]=sgmnt[v*2][i]+sgmnt[v*2+1][i];
}

void add(int bit,int L,int R,int v=1,int l=1,int r=n){
	for(int i=0;i<=20;i++){
		if(lzy[v][i]%2){
			if(l!=r)lzy[v*2][i]++,lzy[v*2+1][i]++;
			lzy[v][i]++;
			sgmnt[v][i]=r-l-sgmnt[v][i]+1;//0base
		}
	}
	if(R<l||L>r)return ;
	if(L<=l&&R>=r){
		sgmnt[v][bit]=r-l-sgmnt[v][bit]+1;//0base
		if(l!=r)lzy[v*2][bit]++,lzy[v*2+1][bit]++;
		return ;
	}
	int mid=l+r>>1;
	add(bit,L,R,v*2,l,mid);
	add(bit,L,R,v*2+1,mid+1,r);
	sgmnt[v][bit]=sgmnt[v*2][bit]+sgmnt[v*2+1][bit];
	
}

void sum(int L,int R,int v=1,int l=1,int r=n){
	if(R<l||L>r)return ;
	for(int i=0;i<=20;i++){
		if(lzy[v][i]%2){
			if(l!=r)lzy[v*2][i]++,lzy[v*2+1][i]++;
			lzy[v][i]++;
			sgmnt[v][i]=r-l-sgmnt[v][i]+1;//0base
		}
	}
	if(L<=l&&R>=r){
		for(int i=0;i<=20;i++)sm+=sgmnt[v][i]*(1<<i);
		return ;
	}
	int mid=l+r>>1;
	sum(L,R,v*2,l,mid);
	sum(L,R,v*2+1,mid+1,r);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	build();
	int m;cin>>m;
	while(m--){
		int q;cin>>q;
		if(q==1){
			sm=0;
			int l,r;cin>>l>>r;
			sum(l,r);
			cout<<sm<<'\n';
		}
		else{
			int l,r,x;cin>>l>>r>>x;
			for(int i=0;i<=20;i++)if(x&(1<<i))add(i,l,r);
		}
	}
	
}