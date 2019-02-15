///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
// #define int long long
#define F first
#define S second
using namespace std;
// void null(){return ;}
const int INF=3e18+9237;
const int maxn=5e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a,b,t,n,w[maxn];
string s;

bool check(int c){
	if(c==0)return true;
	for(int i=0;i<c;i++)
		if(a*(c-1+min(i,c-i-1))+b*(w[n-1]-w[n-i-1]+w[c-i-1])+c<=t)
			return true;
	return false;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b>>t>>s;
	for(int i=0;i<n;i++)w[i]=(i?w[i-1]:0)+(s[i]=='w'?1:0);
	// for(int i=0;i<n;i++)cout<<w[i]<<" ";cout<<endl;
	int ans=0,l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	// cout<<BS(0,n);
}
