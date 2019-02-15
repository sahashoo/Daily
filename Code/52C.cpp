#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int INF=1e9+854;
const int MAXN=2e5+7;
int seg[MAXN*4],lzy[MAXN*4],n;

void shift(int v,int l,int r){
	int lc=v*2,rc=v*2+1;
	lzy[lc]+=lzy[v];
	lzy[rc]+=lzy[v];
	seg[lc]+=lzy[v];
	seg[rc]+=lzy[v];
	lzy[v]=0;
}

void update(int x,int y,int val,int v=1,int l=0,int r=n){
	if(l>=y||r<=x)return;
	if(x<=l&&r<=y){
		seg[v]+=val;
		lzy[v]+=val;
		return ;
	}
	shift(v,l,r);
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	update(x,y,val,lc,l,mid);
	update(x,y,val,rc,mid,r);
	seg[v]=min(seg[rc],seg[lc]);
}

int get(int x,int y,int v=1,int l=0,int r=n){
	if(l>=y||r<=x)return INF;
	if(x<=l&&r<=y)return seg[v];
	shift(v,l,r);
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	int a=get(x,y,lc,l,mid);
	int b=get(x,y,rc,mid,r);
	return min(a,b);
}

int32_t main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin>>n;
	for(int i=0,a;i<n;i++)
		cin>>a,update(i,i+1,a);
	int m;cin>>m;
	while(m--){
		int r,l,val;cin>>l>>r;
		bool type=(getchar()==' ');
		if(type){
			cin>>val;
			if(l>r){
				update(0,r+1,val);
				update(l,n,val);
			}
			else
				update(l,r+1,val);
		}
		else{
			if(l>r)
				cout<<min(get(0,r+1),get(l,n))<<endl;
			else cout<<get(l,r+1)<<endl;
		}
	}
}
