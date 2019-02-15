///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
int n,mod,a[maxn],fct[maxn],res[maxn],ans=1;
map<int,int>mp;

int exppw(int a,int q){
    a%=mod;
    if(q==0)return 1;
    return ((q%2==1?a:1)*exppw(a*a,q/2))%mod;
}

void fact(){
	fct[0]=1;
	for(int i=1;i<maxn;i++){
		int cur=i,cnt=0;
		while(cur%2==0)cur/=2,cnt++;
		fct[i]=(fct[i-1]*cur)%mod;
		res[i]=cnt+res[i-1];
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n*2;i++)cin>>a[i],mp[a[i]]++;
	cin>>mod;
	fact();int cnt=0;
	for(int i=0;i<n;i++)if(a[i]==a[n+i])cnt--;
	for(auto x:mp)ans=(ans*fct[x.S])%mod,cnt+=res[x.S];
	ans=(ans*exppw(2,cnt))%mod;
	cout<<ans;
}
