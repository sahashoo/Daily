///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e4;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c;cin>>a>>b>>c;
	a*=10;
	for(int i=1;i<MAXN;i++){
		if(a/b==c)return cout<<i,0;
		a=(a%b)*10;
	}
	cout<<-1;
}
