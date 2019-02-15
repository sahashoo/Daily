#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
char v[26];
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<26;i++)v[i]='a'+i;
	for(int i=0;i<m;i++) {
		string c,d;
		cin>>c>>d;
		for(int j=0;j<26;j++){
			if(v[j]==c[0])v[j]=d[0];
			else if(v[j]==d[0])v[j]=c[0];
		}
	}
	for(int i=0;i<s.size();i++) {
		s[i]=v[s[i]-97];
	}
	cout<<s;
}