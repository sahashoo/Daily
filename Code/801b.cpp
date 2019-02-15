///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
string s,t;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s>>t;
	for(int i=0;i<s.size();i++)if(s[i]<t[i])return cout<<-1,0;
	cout<<t;
}
