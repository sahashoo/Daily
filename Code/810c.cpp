///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+7,mod=1e9+7;
int n,a[maxn],ans,pw[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0]=1;
	for(int i=1;i<maxn;i++)pw[i]=(pw[i-1]*2)%mod;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		int add=((pw[i]-1+mod)*(pw[n-i]-1+mod))%mod;
		ans=(ans+(a[i]-a[i-1])*add)%mod;
	}
	cout<<ans;
}