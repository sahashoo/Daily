///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
string s,t;
bool at;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	t+=s[0];
	int n=s.size();
	for(int i=1;i<n;i++){
		if(i+2<n-1&&s[i]=='d'&&s[i+1]=='o'&&s[i+2]=='t')
			t+='.',i+=2;
		else if(i+1<n-1&&s[i]=='a'&&s[i+1]=='t'&&at==false)t+='@',i++,at=true;
		else t+=s[i];
	}
	cout<<t;
}
