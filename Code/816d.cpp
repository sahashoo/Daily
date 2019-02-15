///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7,mod=1e9+7;
int a[maxn],n,mrk=1;

int pw(int a,int q) {
    a%=mod;
    if(q==0)return 1;
    return((q%2==1?a:1)*pw(a*a,q/2))%mod;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n%4!=1){
		n--;
		for(int i=1;i<=n;i++){
			a[i]=(a[i]+mrk*a[i+1]+mod)%mod;
			mrk*=-1;
		}
    }
	int res=a[1],p=1;
	for(int i=1;i<=n/2;i++){
		p=p*(n/2-i+1)%mod*pw(i,mod-2)%mod;
		res=(res+p*a[i*2+1])%mod;
    }
	//res=(res+mod)%mod;
	cout<<res;
}