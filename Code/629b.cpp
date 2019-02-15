#include<bits/stdc++.h>
using namespace std;
int n,f[370],m[370],ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int b,e;
		cin>>s>>b>>e;
		if(s[0]=='M'){for(int j=b;j<=e;j++)m[j]++;}
		if(s[0]=='F'){for(int j=b;j<=e;j++)f[j]++;}
	}
	for(int i=0;i<370;i++)ans=max(ans,min(f[i],m[i]));
	cout<<ans*2;
}