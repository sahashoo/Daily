///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7,mod=1e9+7;
int n,k,sum[maxn],res,cnt;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(i<=k)cnt++;
		if(i>n-k+1)cnt--;
		res+=a*cnt;
	}
	double ans=(double)res/(n-k+1);
	cout<<fixed<<setprecision(12)<<ans;
}
