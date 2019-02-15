#include<bits/stdc++.h>
using namespace std;
long long int ans;
int k,val,arr[27];
string s;
int main(){
	cin>>s;
	cin>>k;
	for(int i=0;i<26;i++){
		cin>>arr[i];
		val=max(val,arr[i]);
	}
	for(int i=0;i<s.size();i++)	ans=ans+(arr[s[i]-97]*(i+1));
	for(int i=s.size()+1;i<=k+s.size();i++)	ans=ans+(val*i);
	cout<<ans;
}