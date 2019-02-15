#include<bits/stdc++.h>
using namespace std;
int b1,r1,n,b2,r2;
string s;

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='b'){
			if(i%2)	b2++;
			else b1++;
		}
		else{
			if(i%2)	r2++;
			else r1++;
		}
	}
	cout<<min(max(b1,r2),max(b2,r1));
}