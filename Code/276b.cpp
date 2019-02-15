#include<bits/stdc++.h>
using namespace std;
int k,a[30];
string s;

int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)a[s[i]-'a']++;
	for(int i=0;i<30;i++)if(a[i]%2==1)k++;
	if(k%2==1||k==0)cout<<"First";
	else cout<<"Second";
}