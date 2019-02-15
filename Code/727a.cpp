///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int a,b;
vector<int>res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b;
	while(b>=1){
		res.push_back(b);
		if(b==a){
			cout<<"YES"<<endl<<res.size()<<endl;
			for(int i=res.size()-1;i>=0;i--)cout<<res[i]<<" ";
			return 0;
		}
		if(b%10==1){b--;b/=10;}
		else if(b%2==0)b/=2;
		else return cout<<"NO",0;
	}
	cout<<"NO";
}
