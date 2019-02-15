///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int m,res[maxn];
string s;

bool check(int i,int t){
	if(i>m)return true;
	for(int j=10;j>t;j--){
		if(j==res[i-1]||s[j]=='0')continue;
		res[i]=j;
		if(check(i+1,j-t))return true;
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s>>m;s='0'+s;
	if(check(1,0)==false)return cout<<"NO",0;
	cout<<"YES"<<endl;
	for(int i=1;i<=m;i++)cout<<res[i]<<" ";
}
