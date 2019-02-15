///Age Yekam Bekshi Beham is NO Problem .-.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,s,v1,v2,t1,t2;cin>>s>>v1>>v2>>t1>>t2;
	a=v1*s;a+=t1+t1;
	b=v2*s;b+=t2+t2;
	if(a==b)cout<<"Friendship";
	else if(a>b)cout<<"Second";
	else if(a<b)cout<<"First";
}