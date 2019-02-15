///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int E[2],O[2],cntE,cntO;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		cntO++;
		int c=s[i]-'a';
		if(i&1)cntO+=O[c],cntE+=E[c],O[c]++;
		else cntO+=E[c],cntE+=O[c],E[c]++;
	}
	cout<<cntE<<" "<<cntO;
}
