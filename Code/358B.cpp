#include<bits/stdc++.h>
using namespace std;
string s,a="<3";
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		a+=s+"<3";
	}
	cin>>s;
	n=0;
	for(int i=0;i<s.size();i++){
		n+=(s[i]==a[n]);
	}
	cout<<((n==a.size())?"yes":"no");
}