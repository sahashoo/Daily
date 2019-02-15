///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
const int N=3e5+7;
const int MAXN=2e3+7;
const int mod=1e9+7;
pair<int,int>a[MAXN];
int fct[N],inv[N];
int dp[MAXN];

inline int pw(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=(a*ret)%mod;
		a=(a*a)%mod;b/=2;
	}
	return ret;
}

inline int C(int a,int b){
	if(a>b)return 0;
	else return (fct[b]*((inv[a]*inv[b-a])%mod))%mod;
}
inline void precomput(){
	fct[0]=1;
	for(int i=1;i<N;i++)fct[i]=(fct[i-1]*i)%mod;
	inv[N-1]=pw(fct[N-1],mod-2);
	for(int i=N-1;i>0;i--)inv[i-1]=(inv[i]*i)%mod;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	precomput();
	int n,m,k;cin>>n>>m>>k;
	for(int i=0,x,y;i<k;i++)cin>>x>>y,a[i]={x-1,y-1};
	sort(a,a+k);
	int ans=C(n-1,n+m-2);
	for(int i=0;i<k;i++){
		int tmp=C(a[i].F,a[i].F+a[i].S);
		// cout << "----------" << a[i].F << " " << a[i].S << " " << tmp << "\n";
		for(int j=0;j<i;j++)
			if(a[j].S<=a[i].S){
				tmp=(tmp-((dp[j]*C(a[i].F-a[j].F , a[i].F-a[j].F+a[i].S-a[j].S))%mod))%mod;
				tmp+=(tmp<0?mod:0);
			}
		dp[i]=tmp;
		tmp=(tmp*C(n-1-a[i].F , n+m-2-a[i].F-a[i].S))%mod;
		tmp+=(tmp<0?mod:0);
		ans-=tmp;
		ans+=(ans<0?mod:0);
		// cout<< "--------" << tmp << " " << ans << endl;
	}
	cout<<ans;
}
