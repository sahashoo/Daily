///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
using namespace std;
const ld eps=1e-15,ZERO=0;
const int MAXN=2e5+7;
const int X=2e4+10;
ld smn[MAXN],smx[MAXN];
int n,a[MAXN];

inline ld check(ld x){
	smx[0]=smn[0]=a[0]-x;
	ld ret=abs(smn[0]);
	for(int i=1;i<n;i++){
		smn[i]=min(smn[i-1],ZERO)+a[i]-x;
		smx[i]=max(smx[i-1],ZERO)+a[i]-x;
		ret=max(ret,max(abs(smx[i]),abs(smn[i])));
	}
	return ret;
}

inline ld BS(ld l=-X,ld r=X){
	while(r-l>=eps){
		ld L=(2*l+r)/3,R=(2*r+l)/3;
		// cout<<"------"<<L<<" "<<R<<" "<<check(L)<<" "<<check(R)<<endl;
		if(check(L)<check(R))r=R;
		else l=L;
	}
	return l;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(12);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<check(BS());
}
