#include<bits/stdc++.h>
using namespace std;
string s;
int n,d,t;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t>>s; 
		if((d==0&&s!="South")||(d==20000&&s!="North")||d<0||d>20000){
			cout<<"NO";
			return 0;
		}
		if(s=="North") d=d-t;
		else if(s=="South") d=d+t;
	}
	if(d!=0)cout<<"NO";
	else cout<<"YES";
}