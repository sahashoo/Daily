#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	string s,d,ans="";
	cin>>s>>d;
	ans.resize(s.size());
	for(int i=0;i<s.size();i++)(s[i]!=d[i]?ans[i]='1':ans[i]='0');
	cout<<ans;
}