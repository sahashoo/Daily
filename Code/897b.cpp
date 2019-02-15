///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k,p,cnt=0,num=0,sum=0;cin>>k>>p;
	vector<int>a,vec;
	while(num<k){
		int tmp=++num,ret=num;
		while(tmp)ret=(ret*10+(tmp%10))%p,tmp/=10;
		sum=(sum+ret)%p;
	}
	cout<<sum;
}
