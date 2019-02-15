///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c,d;cin>>a>>b>>c>>d;
	while(b!=d&&b<1e7)(b<d?b+=a:d+=c);
    cout<<(b==d?b:-1);
}
