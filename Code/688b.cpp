#include<bits/stdc++.h>
using namespace std;
string s,d;
int main(){
	cin>>s;
	d=s;
	reverse(d.begin(),d.end());
	cout<<s<<d;
}