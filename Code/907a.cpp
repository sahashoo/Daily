///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c,d;cin>>a>>b>>c>>d;
	if(d>2*c||d>=b||2*d<c)return cout<<-1,0;
	cout<<a*2<<'\n'<<2*b<<'\n'<<c*(d<=c?1:2);
}
