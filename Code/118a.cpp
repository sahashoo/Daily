///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
string s,t;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='Z')s[i]+=32;
		if(s[i]=='a'||s[i]=='o'||s[i]=='y'||s[i]=='e'||s[i]=='u'||s[i]=='i')continue;
		t=t+"."+s[i];
	}
	cout<<t;
}
