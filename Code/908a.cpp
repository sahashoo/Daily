#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
int cnt;
string w="aeiou13579";

bool vow(char c){
	for(char x:w)
		if(x==c)return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	for(int i=0;i<sz(s);i++){
		if(vow(s[i]))cnt++;
	}
	cout<<cnt;
}
