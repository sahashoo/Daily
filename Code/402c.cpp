#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	//for(int i=1;i<=5;i++)for(int j=i+1;j<=5;j++)sample.push_back({i,j});
	int t;cin>>t;
	while(t--){
		int n,p;cin>>n>>p;
		int e=(2*n)+p;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(e<=0)break;
				cout<<i<<" "<<j<<'\n';e--;
			}
		}
	}
}