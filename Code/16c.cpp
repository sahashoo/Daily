#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int a,b,x,y;

int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>x>>y;
    int bmm=gcd(x,y);
	x/=bmm;y/=bmm;
	int n=a/x,m=b/y;
	cout<<x*min(n,m)<<" "<<y*min(n,m);
}
