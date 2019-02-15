#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	cin>>s;
	if(s.size()>1)	n=(s[s.size()-2]-48)*10;
	n=n+s[s.size()-1]-48;
	if(n%4==0)	cout<<"4";
	else cout<<"0";
}