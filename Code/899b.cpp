///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
string lp="424343443434";
string xp="414343443434";
string a=xp+xp+xp;
string b=lp+xp+xp;
string c=xp+lp+xp;
string d=xp+xp+lp,t;

bool check(string &s){
	for(int i=0;i+t.size()<s.size();i++){
		bool c=true;
		for(int j=0;j<t.size();j++)
			if(s[i+j]!=t[j]){c=false;break;}
		if(c)return true;
	}
	return false;;
}

int32_t main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++){
		cin>>x;
		if(x==28)t=t+"1";
		if(x==29)t=t+"2";
		if(x==30)t=t+"3";
		if(x==31)t=t+"4";
	}
	if(check(a)||check(b)||check(c)||check(d))cout<<"Yes";
	else cout<<"No";
}
