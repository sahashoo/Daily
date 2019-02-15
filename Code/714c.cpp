///age yekam bekeshi be ham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;

string nts(int a){
	string s="";
	for(int i=0;i<18;i++){
		if((a%10)%2)s='1'+s;
		else s='0'+s;
		a/=10;
	}
	return s;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		char c;cin>>c;
		if(c!='?'){
			int a;cin>>a;
			string s=nts(a);
			if(c=='+')mp[s]++;
			else mp[s]--;
		}
		else{
			string s;cin>>s;
			while(s.size()<18)s='0'+s;
			cout<<mp[s]<<'\n';
		}
	}
}