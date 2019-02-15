#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n,k,g,b;cin>>n>>k>>g>>b;
	if(g>k*(b+1)||b>k*(g+1))return cout<<"NO",0;
	int cnt=0;
	while(g>b&&g>0){
		cnt++;g--;
		cout<<"G";
		if(cnt==k&&b>0)cout<<"B",b--,cnt=0;
	}
	while(b>g&&b>0){
		cnt++;b--;
		cout<<"B";
		if(cnt==k&&g>0)cout<<"G",g--,cnt=0;
	}
	for(int i=0;i<b;i++)cout<<"GB";
}