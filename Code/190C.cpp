#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
string s,ans;
int n,t;

void solve(){
	if(cin>>s){
		ans+=s;
		if(s=="pair"){
			ans+='<';
			solve();
			ans+=',';
			solve();
			ans+='>';
		}
		else t++;
	}
	else{
		cout<<"Error occurred";
		exit(0);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	solve();
	if(t!=n)cout<<"Error occurred";
	else if(cin>>s)cout<<"Error occurred";
	else cout<<ans;
}