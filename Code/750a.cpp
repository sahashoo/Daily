#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
int main(){
	cin>>n>>k;
	k=240-k;
	for(int i=1;i<=n;i++){
		k=k-(5*i);
		if(k>=0)	ans++;
	}
	cout<<ans;
}