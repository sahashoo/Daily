#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n;string k;

int stn(string s){
	int a=0;
	for(int i=0;i<s.size();i++){a+=(s[s.size()-1-i]-'0')*pow(10,i);}
	return a;
}

int solve(int pos,int p) {
	if(pos==-1)return 0;
	int len=min((int)10,pos+1);
	string tmp=k.substr(pos-len+1,len);
	for(int i=len;i>=1;i--){
		if(tmp[0]!='0'||tmp.size()==1) {
			int d=stn(tmp);
			if(d<n)return solve(pos-i,p*n)+d*p;
		}
		tmp.erase(0,1);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	cout<<solve(k.size()-1,1);
}