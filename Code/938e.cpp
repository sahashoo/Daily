#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e6+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[MAXN],fct[MAXN],inv[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	fct[0]=inv[n+1]=1;
	for(int i=1;i<n+2;i++){
		fct[i]=(fct[i-1]*i)%mod;
	}
	for(int i=n;i>0;i--){
		inv[i]=(inv[i+1]*i)%mod;
	}
	sort(a+1,a+n+1);
	int t=0,cur=0,ans=0;
	for(int i=1;i<=n&&a[i]!=a[n];i++){
		if(a[i]==a[i-1])cur++;
		else t+=cur,cur=1;
		int temp=(fct[n-t-1]*inv[n-t+1])%mod;
		ans=(ans+(temp*a[i])%mod)%mod;
    }
	cout<<ans;
	
}
