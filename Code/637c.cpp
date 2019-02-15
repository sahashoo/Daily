///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,res=13;
string s[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cur=0;
			for(int k=0;k<6;k++)cur+=(s[i][k]!=s[j][k]);
			res=min(res,cur);
		}
	}
	cout<<(res-1)/2;
}
