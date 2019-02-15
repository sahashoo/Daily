#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
string s;
int sum;
vector<int>rmn[5];

void DelS0(string &a){
	int i;
	for(i=0;i<(int)a.size()-1&&a[i]=='0';i++);
	a=a.substr(i);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int sln=s.size();
	for(int i=0;i<sln;i++)sum=(sum+s[i]-'0')%3,rmn[(s[i]-'0')%3].push_back(i);
	if(sum==0)return cout<<s,0;
	if(sum==2)swap(rmn[1],rmn[2]);
	string res="";
	if(rmn[1].size()>0){
		string scp=s;
		scp.erase(scp.begin()+rmn[1].back());
		DelS0(scp);
		if(scp.size()>res.size())res=scp;
	}
	if(rmn[2].size()>1){
		string scp=s;
		scp.erase(scp.begin()+rmn[2].back());
		scp.erase(scp.begin()+rmn[2][rmn[2].size()-2]);
		DelS0(scp);
		if(scp.size()>res.size())res=scp;
	}
	if(res!="")cout<<res;
	else cout<<-1;
	
}