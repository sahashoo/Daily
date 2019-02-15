#include<bits/stdc++.h>
using namespace std;
int n,a[107],b[107];

int mor(){
	for(int i=0;i<n;i++)if(a[i]<=b[i])return 0;
	return 1;
}
int les(){
	for(int i=0;i<n;i++)if(a[i]>=b[i])return 0;
	return 1;	
}

int main(){
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){a[i]=s[i]-48;b[i]=s[i+n]-48;}
	sort(a,a+n);
	sort(b,b+n);
	if(mor()==1||les()==1)cout<<"YES";
	else cout<<"NO";
}