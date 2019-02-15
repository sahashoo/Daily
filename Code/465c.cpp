///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
string s,t;
int n,p;
//bool fnd,chck;
bool fnd;

bool Check(int i){
	if((i>0&&t[i-1]==t[i])||(i>1&&t[i-2]==t[i]))return false;
	return true;
}

void FOR(int i,bool chck){
	if(i>=n){
		if(chck==true){
			cout<<t;
			fnd=true;
		}
		return;
	}
	for(t[i]=(chck?'a':s[i]);t[i]<'a'+p&&fnd==false;t[i]++)
		if(Check(i))FOR(i+1,chck||t[i]>s[i]);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>p>>s;
	t.resize(n);
	FOR(0,false);
	if(!fnd)cout<<"NO";
}
