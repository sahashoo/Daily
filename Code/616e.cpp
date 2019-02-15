///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,m,k,l,r,L,R,res;

void calc(int m){
	k=n/m;
	r=n%m%mod;
	l=(n/(k+1))+1;
	L=(m-l+1)%mod;
	res=(res+L*r+k%mod*(L*(L-1)/2%mod))%mod;
	if(l-1!=0)calc(l-1);
}

int32_t main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	calc(m);
	cout<<res;
}
