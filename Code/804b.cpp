#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+3;
const int mod=1e9+7;
int ans,b;
string d;

int main(){
	cin>>d;
	for(int i=d.size()-1;i>=0;i--){
		if(d[i]=='b')b=(b+1)%mod;
		else{
			ans=(ans+b)%mod;
			b=(b*2)%mod;
		}
	}
	cout<<ans;
}