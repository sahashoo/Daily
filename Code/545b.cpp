#include<bits/stdc++.h>
using namespace std;
int c;
string s,t,p;
int main(){
	cin>>s>>t;
	p=s;
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i]){
			if(c%2)	p[i]=t[i];
			c++;
		}
	}
	if(c%2)	cout<<"impossible";
	else cout<<p;
}