#include<bits/stdc++.h>
#define int long long
using namespace std;
int s,n;

bool nts(int a){
	int f=a,sumc=0;
	while(f){sumc+=f%10;f=f/10;}
	if(a-sumc>=s)return true;
	else return false;
}

int32_t main(){
	cin>>n>>s;
	for(int i=s;i<=n;i++)if(nts(i))return cout<<n-i+1,0;
	cout<<0;
}