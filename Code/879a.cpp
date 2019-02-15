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

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,n,res=0;cin>>n;
	while(n--){
		cin>>a>>b;
		if(a>res){res=a;continue;}
		res=((res-a)/b+1)*b+a;
	}
	cout<<res;
}
