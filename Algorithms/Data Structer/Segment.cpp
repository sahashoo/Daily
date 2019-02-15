#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,q,a[maxn],sgmnt[100*maxn];

void build(int v=1,int l=0,int r=n){
	if(r-l<2){
		seg[v]=a[l];
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	build(a,lc,l,mid);
	build(a,rc,mid,r);
	seg[v]=max(seg[lc],seg[rc]);
}

void update(int val,int id,int v=1,int l=0,int r=n){
	if(id<l||id>r)return ;
	if(r-l<2){
		seg[v]=val;
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	update(val,id,lc,l,mid);
	update(val,id,rc,mid,r);
	seg[v]=max(seg[lc],seg[rc]);
}

int query(int x,int y,int v=1,int l=0,int r=n){
	if(x=>r||y<=l)return -INF;
	if(x<l&&y>r)return seg[v];
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	int a=act(x,y,lc,l,mid);
	int b=act(x,y,rc,mid,r);
	return max(a,b);
}


int32_t main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	build();
	for(int i=0;i<q;i++){
		int mood,l,r,ind,val;
		cin>>mood;
		if(mood){
			cin>>ind>>val;
			update(val,ind);
		}
		else{
			cin>>l>>r;
			cout<<act(l,r);
		}
	}
}
