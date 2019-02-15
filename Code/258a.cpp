///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
string s;
bool c;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size()-1;i++)
		if(c||s[i]=='1')cout<<s[i];
		else if(c==false&&s[i]=='0')c=true;
	if(c)cout<<s[s.size()-1];
}