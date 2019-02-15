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
	int n;cin>>n;
	int s=ceil(sqrt(n));
	cout<<(4*s)-((abs(n-(s*s))/s)*2);
	//cout<<"\n"<<(((n-(s*s))/s)*2)<<" "<<4*s;
}
