///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,k;
string s;

int dp(char a,char b){
	int r=0,lft=k,res=0;
	for(int i=0;i<n;i++){
		if(r<i)r=i,lft=k;
		while(r<n&&(s[r]==a||(lft>0&&s[r]==b)))lft-=(s[r]==b),r++;
		res=max(res,r-i);
		lft+=(s[i]==b);
	}
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>s;
	cout<<max(dp('a','b'),dp('b','a'))<<endl;;
}
