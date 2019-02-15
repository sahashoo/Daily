///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;

int pr(int x){
	if(x%4==0)return x/4;
	if(x%4==1)
		if(x==1||x==5)return -1;
		else return (x-9)/4+1;
	if(x%4==2)
		if(x==2)return -1;
		else return (x-6)/4+1;
	if(x%4==3)
		if(x==3||x==7||x==11)return -1;
		else return (x-15)/4+2;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q,n;cin>>q;
	while(q--)cin>>n,cout<<pr(n)<<'\n';
}