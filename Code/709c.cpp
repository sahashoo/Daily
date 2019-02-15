#include<bits/stdc++.h>
using namespace std;
string s;
bool a;

int32_t main(){
	cin>>s;
	int i=0;
	while(s[i]=='a')i++;
	if(i>=s.size())s[s.size()-1]='z';
	else while(s[i]!='a'&&i<s.size())s[i++]-=1;
	cout<<s;
}