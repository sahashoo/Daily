///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int a,b,n,x;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>n>>x;
	while(n){
		if(n%2)x=(a*x+b)%mod;
		b=b*(a+1)%mod;
		a=(a*a)%mod;
		n/=2;
	}
	cout<<x;
}
