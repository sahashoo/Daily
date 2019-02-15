///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,sum=0,mn=360;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int tmp=a[r]-a[l-1];
			mn=min(abs(sum-2*tmp),mn);
		}
	}
	cout<<mn;
}
