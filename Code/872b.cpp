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
int mn=INF,mx=-INF,a,b;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0,x;i<n;i++){
		cin>>x,mx=max(mx,x),mn=min(mn,x);
		if(i==0)a=x;
		if(i==n-1)a=max(a,x);
	}
	if(k==2)cout<<a;
	else cout<<(k==1?mn:mx);
}
