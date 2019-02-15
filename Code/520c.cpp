#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int a[255];

int32_t main(){
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<n;i++)a[s[i]]++;
	int mx=0,cnt=0;
	for(int i='A';i<='Z';i++){
		if(a[i]>mx)mx=a[i],cnt=0;
		if(a[i]==mx)cnt++;
	}
	int pw=1;
	for(int i=0;i<n;i++)pw=(pw*cnt)%mod;
	cout<<pw;
}