///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;

bool solve(int x){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(3*i+7*j==x)return true;
			if(3*i+7*j>100)break;
		}
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		cout<<(solve(x)?"YES\n":"NO\n");
	}
}
