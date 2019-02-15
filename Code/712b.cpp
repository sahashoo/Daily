#include<Bits/stdc++.h>
using namespace std;
int u,r,l,d;
string s;

int main(){
	cin>>s;
	if(s.size()%2){cout<<-1;return 0;}
	for(int i=0;i<s.size();i++){
		if(s[i]=='L')l++;
		if(s[i]=='D')d++;
		if(s[i]=='R')r++;
		if(s[i]=='U')u++;
	}
	if((abs(d-u)%2)+(abs(l-r)%2)==1){cout<<-1;return 0;}
	cout<<(abs(d-u)+abs(l-r))/2;
}