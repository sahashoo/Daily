///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,k,p,res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;int k2=2*k;
	for(int i=0;i<n;i++){
		int w;cin>>w;
		int d=(w%k?(w/k)+1:w/k);
		res+=d/2;
		if(d%2)p++;
	}
	if(p%2)p++;p/=2;
	cout<<res+p;//<<" "<<res<<" "<<p;
}
