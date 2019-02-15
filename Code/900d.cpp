///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
const int mod=1e9+7;
int dp[MAXN];
vector<int>vec;

int pw(int a,int b){return(b==0?1:(pw((a*a)%mod,b/2)*(b%2?a:1))%mod);}


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y;cin>>x>>y;
	if(y%x)return cout<<0,0;
	y/=x;
	for(int i=1;i*i<=y;i++){
		if(y%i==0){
			vec.push_back(i);
			if(y/i!=i)vec.push_back(y/i);
		}
	}
	sort(vec.begin(),vec.end());
	dp[0]=1;
	for(int i=1;i<vec.size();i++){
		dp[i]=pw(2,vec[i]-1);
		// cout<<vec[i]-1<<" "<<dp[i]<<endl;
		for(int j=0;j<i;j++)
			if(vec[i]%vec[j]==0){
				dp[i]-=dp[j];
				dp[i]%=mod;
				dp[i]+=mod;
				dp[i]%=mod;
			}
	}
	cout<<dp[vec.size()-1];
}
