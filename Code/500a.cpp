#include<bits/stdc++.h>
using namespace std;
int n,a[33000],t;

int main(){
	cin>>n>>t;
	for(int o=1;o<n;o++)	cin>>a[o];
	int i=1;
	if(i==t){cout<<"YES";return 0;}
	while(i<=n){
		i+=a[i];
		if(i==t){cout<<"YES";return 0;}
		if(a[i]==0)	i+=5;
	}
	cout<<"NO";
}