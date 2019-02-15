#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,mod;

int pw(int a,int b){
	return(b==0?1:(pw((a*a)%mod,b/2)*(b%2?a:1))%mod);
}

int pw(int a,int b){
	if(b==0)return 1;
	int temp=pw(a*a,b/2)%mod;
	if(b&1)temp*=a;
	return temp;
}

int32_t main(){
	cin>>x>>n>>mod;
	cout<<pw(x,n);
}
