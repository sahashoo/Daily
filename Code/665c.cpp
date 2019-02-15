#include<bits/stdc++.h>
using namespace std;
string s;

int32_t main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]==s[i+1]&&s[i+1]==s[i+2])s[i+1]=(s[i]=='z'?'a':s[i]+1);
		while(s[i]==s[i-1]||s[i]==s[i+1])s[i]=(s[i]=='z'?'a':s[i]+1);
	}
	cout<<s;
}