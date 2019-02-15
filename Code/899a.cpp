///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a=0,b=0;cin>>n;
	for(int i=0,x;i<n;i++){
		cin>>x;
		if(x==1)a++;
		else b++;
	}
	if(b>=a)cout<<a;
	else
		cout<<b+(a-b)/3;
}
