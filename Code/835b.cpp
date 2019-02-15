///Age Yekam Bekshi Beham is NO Problem .-.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
queue<int>num[10];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k,sum=0,cnt=0;
	string s;cin>>k>>s;
	for(int i=0;i<s.size();i++)sum+=s[i]-'0',num[s[i]-'0'].push(i);
	if(sum>=k)return cout<<0,0;
	while(sum<k){
		for(int i=0;i<=9;i++){
			if(num[i].size()){
				sum+=9-i;
				num[i].pop();
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
}