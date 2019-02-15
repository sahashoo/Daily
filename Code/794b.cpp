///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,h;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>h;
	for(int i=1;i<n;i++)cout<<fixed<<setprecision(12)<<sqrt(ld(i)/ld(n))*ld(h)<<" ";
}
