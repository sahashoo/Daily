///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn],b[maxn];

int binpw(int a,int b){return (b==0?1:(binpw((a*a)%mod,b/2)*(b%2?a:1))%mod);}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,b[x]++;
	for(int i=maxn;i>=0;i--)b[i]+=b[i+1];
	int res=0;
	for(int i=1;i<maxn;i++){
		int cnt=0,tmp=1;
		for(int j=1;j<=sqrt(i);j++){
			if(i%j==0){
				a[cnt++]=j;
				if(j*j!=i)a[cnt++]=i/j;
			}
		}
		sort(a,a+cnt);
		for(int j=1;j<cnt;j++)tmp=(tmp*binpw(j,b[a[j-1]]-b[a[j]]))%mod;
		res=(res+((tmp*(binpw(cnt,b[i])-binpw(cnt-1,b[i])+mod))%mod))%mod;
	}
	cout<<res;
}