///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
string s;

int GO(int i){
	if(i==s.size())return cout<<i<<'\n',0;
	if(s[i-1]=='l')GO(i+1),cout<<i<<'\n';
	else cout<<i<<'\n',GO(i+1);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	GO(1);
}
