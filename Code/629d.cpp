#include<bits/stdc++.h>
#define int long long
#define ld long double
#define F first
#define S second
using namespace std;
const ld pi=3.1415926535897932384626433832795;
const int maxn=1e5+100;
int sgmnt[maxn*10];
pair<int,int>a[maxn];

void update(int id,int val,int v,int l,int r){
	if(r-l<=1){
		sgmnt[v]=val;
		return;
	}
	int m=(l+r)/2;
	if(id<m)update(id,val,v*2,l,m);
	else update(id,val,v*2+1,m,r);
	sgmnt[v]=max(sgmnt[v],max(sgmnt[v*2],sgmnt[v*2+1]));
}

int mx(int L,int R,int v,int l,int r){
	if(r-l<=1||(L<=l&&r<=R))return sgmnt[v];
	int m=(l+r)/2;
	int tmp=0;
	if(L<m)tmp=max(tmp,mx(L,R,v*2,l,m));
	if(m<R)tmp=max(tmp,mx(L,R,v*2+1,m,r));
	return tmp;
}

int32_t main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int r,h;cin>>r>>h;
		a[i].F=r*r*h;
		a[i].S=-i;
	}
	sort(a,a+n);
	int res=0;
	for(int i=0;i<n;i++){
		int tmp=a[i].F+mx(0,-a[i].S,1,0,n) ;
		res=max(res,tmp);
		update(-a[i].S,tmp,1,0,n);
	}
	cout<<fixed<<setprecision(12)<<pi*(ld)res<<endl;
}