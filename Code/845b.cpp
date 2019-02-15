#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	string s;cin>>s;
	int res=3;
	for(int i=0;i<=1e6;i++){
		int a=i,sum=0,cnt=0;
		for(int j=0;j<6;j++){
			if(j<3)sum+=a%10;
			else sum-=a%10;
			if(a%10!=s[j]-'0')cnt++;
			a/=10;
		}
		if(sum==0)res=min(cnt,res);
	}
	cout<<res;
}