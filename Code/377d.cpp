#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=3e5+7;
pair<int,int>seg[MAXN*8];
vector<int>a[MAXN],b[MAXN];
int l[MAXN],r[MAXN],v[MAXN],lzy[8*MAXN];

void build(int v=1,int l=0,int r=MAXN){
	if(r-l<=1){
		seg[v]={0,l};
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	build(lc,l,mid);
	build(rc,mid,r);
	seg[v]=max(seg[lc],seg[rc]);
}

void add(int v,int x){
	seg[v].F+=x;
	lzy[v]+=x;
}

void shift(int v){
	int lc=v*2,rc=v*2+1;
	add(lc,lzy[v]);
	add(rc,lzy[v]);
	lzy[v]=0;
}

void update(int x,int y,int vl,int v=1,int l=0,int r=MAXN){
	if(x>=r||l>=y)return ;
	if(x<=l&&r<=y){
		add(v,vl);
		return ;
	}
	shift(v);
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	update(x,y,vl,lc,l,mid);
	update(x,y,vl,rc,mid,r);
	seg[v]=max(seg[lc],seg[rc]);
}

pair<int,int> get(int x,int y,int v=1,int l=0,int r=MAXN){
	if(x>=r||l>=y)
		return {-1,-1};
	if(x<=l&&r<=y)
		return seg[v];
	shift(v);
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	auto a=get(x,y,lc,l,mid);
	auto b=get(x,y,rc,mid,r);
	return max(a,b);
}

int32_t main(){
	build();
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i]>>v[i]>>r[i];
		v[i]--;
		l[i]--;
		a[l[i]].push_back(i);
		b[v[i]].push_back(i);
	}
	int ans=0,lb=-1,ub=-1;
	for(int i=0;i<MAXN;i++){
		for(int x:a[i])
			update(v[x],r[x],1);
		pair<int,int>t=get(i,MAXN);
		if(t.F>ans)
			ans=t.F,lb=i,ub=t.S;
		for(int x:b[i])
			update(v[x],r[x],-1);
	}
	cout<<ans<<'\n';
	for(int i=0;i<n;i++)
		if(l[i]<=lb&&r[i]>ub&&v[i]<=ub&&v[i]>=lb)
			cout<<i+1<<" ";
}