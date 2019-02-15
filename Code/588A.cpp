#include<bits/stdc++.h>
using namespace std;
int a,p=1e4,n,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		cin>>a>>s;
		p=min(p,s);
		ans=ans+(p*a);
	}
	cout<<ans;
}