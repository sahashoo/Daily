#include<bits/stdc++.h>
using namespace std;
string s,t;
int ans;
int main(){
	cin>>s>>t;
	if(t.size()>s.size())return cout<<0,0;
	for(int i=0;i<s.size()-t.size()+1;i++){
		bool bl=true;
		for(int j=0;j<t.size();j++)if(s[i+j]!=t[j]){bl=false;break;}
		if(bl){ans++;i=i+t.size()-1;}
	}	
	cout<<ans;
}