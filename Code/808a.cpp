///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18+7;
string s,t;

int stn(string a){
	reverse(a.begin(),a.end());
	int res=0;
	for(int i=0;i<a.size();i++){
		int c=a[i]-'0';
		res+=pow(10,i)*c;
	}
	return res;
}

int32_t main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	int x=s[0]+1-'0';
	//cout<<x<<endl;
	while(x){
		t+=(x%10)+'0';
		x/=10;
	}
	reverse(t.begin(),t.end());
	for(int i=1;i<s.size();i++)t+='0';
//	cout<<t<<endl<<stn(t)<<endl<<stn(s)<<endl;
	cout<<stn(t)-stn(s);
}
