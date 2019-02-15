///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int mod=1e9+7;
int fct[N],inv[N];

long long pw(int a,int b){return(b==0?1:(1ll*pw((1ll*a*a)%mod,b/2)*(b%2?a:1))%mod);}

long long C(int a,int b){return (1ll*fct[a]*((1ll*inv[a-b]*inv[b])%mod))%mod;}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fct[0]=1;
	for(int i=1;i<N;i++)fct[i]=(1ll*fct[i-1]*i)%mod;
	inv[N-1]=pw(fct[N-1],mod-2);
	for(int i=N-1;i>0;i--)inv[i-1]=(1ll*inv[i]*i)%mod;
	
	int n,a,b,res=0;cin>>a>>b>>n;
	for(int x=0;x<=n;x++){
		// cout<<fct[x]<<" "<<inv[x]<<endl;
		int y=n-x;
		int tmp=x*a+y*b;
		string s="";
		bool chk=true;
		while(tmp){
			if(tmp%10!=a&&tmp%10!=b){
				chk=false;break;
			}
			tmp/=10;
		}
		if(chk)res=(res+C(n,x))%mod;
	}
	cout<<res;
}