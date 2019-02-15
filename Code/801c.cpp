///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int maxn=1e5+7,INF=1e18;
ld n,p,a[maxn],b[maxn],t[maxn],sum;

bool check(ld it){
	ld need=0;
	for(int i=0;i<n;i++)need+=max((ld)0,(it-t[i])*a[i]);
	if(p*it>=need)return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i],sum+=a[i],t[i]=((ld)b[i])/((ld)a[i]);
	if(p>=sum)return cout<<-1,0;
	ld l=0,r=INF;
	for(int i=0;i<150;i++){
		ld mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(r>INF)return cout<<-1,0;
	cout<<setprecision(10)<<(ld)l;
}
