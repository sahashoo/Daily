///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a,b;cin>>a>>b;
	if(a.size()!=b.size())return cout<<"NO",0;
	int ta=0,tb=0;
	for(int i=0;i<a.size();i++)
		ta+=(a[i]=='0'),tb+=(b[i]=='0');
	if(ta==tb)return cout<<"YES",0;
	cout<<(ta==a.size()||tb==b.size()?"NO":"YES");
}