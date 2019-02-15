#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=4e6+7;

struct segment{
	int seg[MAXN*4],lzy[4*MAXN];
	void update(int x,int y,int val,int v=1,int l=0,int r=MAXN){
		if(r<=x||y<=l)return ;
		if(x<=l&&r<=y){
			lzy[v]+=val;
			return;
		}
		int mid=(l+r)/2,lc=v*2,rc=lc+1;
		update(x,y,val,lc,l,mid);
		update(x,y,val,rc,mid,r);
		seg[v]= seg[lc]+lzy[lc]*(mid-l);
		seg[v]+=seg[rc]+lzy[rc]*(r-mid);
	}
	int get(int x,int y,int v=1,int l=0,int r=MAXN){
		if(x<=l&&r<=y)return seg[v]+lzy[v]*(r-l);
		if(r<=x||y<=l)return 0;
		int mid=(l+r)/2,lc=v*2,rc=v*2+1;
		int ret=get(x,y,lc,l,mid);
		ret+=get(x,y,rc,mid,r);
		ret+=lzy[v]*(min(y,r)-max(l,x));
		return ret;
	}
}X,Y;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	while(q--){
		int t,lx,ly,rx,ry;
		cin>>t>>lx>>ly>>rx>>ry;
		lx--,ly--;
		if(t){
			int temp=0;
			temp=2*X.get(lx,rx);
			temp-=X.seg[1];
			temp+=2*Y.get(ly,ry);
			temp-=Y.seg[1];
			cout<<temp/2<<'\n';
		}
		else{
			int x;cin>>x;
			X.update(lx,rx,(ry-ly)*x);
			Y.update(ly,ry,(rx-lx)*x);
		}
	}
}