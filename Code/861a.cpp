///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	int t5=0,t2=0;
	int cn=n;
	while(cn%5==0)t5++,cn/=5;
	while(cn%2==0)t2++,cn/=2;
	cout<<(int)(pow(2,max(0ll,k-t2))*pow(5,max(0ll,k-t5))*n);
}
