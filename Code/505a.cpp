#include<bits/stdc++.h>
using namespace std;
int ab=100007,ba=100007,ab1=100007,ba1=100007;
string s;

int main(){
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='B')ab=min(ab,i+1);
		if(s[i]=='B'&&s[i+1]=='A')ba=min(ba,i+1);
	}
	if(ab==100007&&ba==100007)ab=0,ba=0;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&ba<i)ab1=min(ab1,i+1);
		if(s[i]=='B'&&s[i+1]=='A'&&ab<i)ba1=min(ba1,i+1);
	}
	if(ab1==100007&&ba1==100007)ab1=0,ba1=0;
	if((ab&&ba1)||(ab1&&ba))cout<<"YES";
	else cout<<"NO";
}