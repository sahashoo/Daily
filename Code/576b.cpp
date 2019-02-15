#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,in,ans,tmp;
string s;
map<ll,ll>	lib;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>s>>in;
		if(s[0]=='+'){
			tmp++;
			ans=max(ans,tmp);
			lib[in]++;
		}
		else if(lib[in]==0)	ans++;
		else tmp--,lib[in]--;
	}
	cout<<ans<<endl;
}