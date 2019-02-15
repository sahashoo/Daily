#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int32_t main(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int>v;
	for(int i=0;i<n;i++){
		int a=s[i]-'0';
		if(a==2||a==5||a==7||a==3)v.pb(a);
		if(a==4)v.pb(3),v.pb(2),v.pb(2);
		if(a==6)v.pb(5),v.pb(3);
		if(a==8)v.pb(7),v.pb(2),v.pb(2),v.pb(2);
		if(a==9)v.pb(7),v.pb(3),v.pb(3),v.pb(2);
	}
	sort(v.begin(),v.end(),greater<int>() );
	for(auto x:v)cout<<x;
}