///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int x,y,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			char c;cin>>c;
			if(c=='1'){
				ans=abs(i-3)+abs(j-3);
			}
		}
	}
	cout<<ans;
}
