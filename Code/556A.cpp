#include<bits/stdc++.h>
using namespace std;
int n,y,d;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]==49) y++;
		else d++;
	}
	cout<<n-(min(y,d)*2);
	
}