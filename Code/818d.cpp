///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7,INF=1e18+7;
int c[maxn],n,a,b=-1,cnt,res[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>a;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x==a)cnt++;
		else{
			if(c[x]<cnt)res[x]=-INF;
			else res[x]++;
			c[x]++;
		}
	}
	for(int i=1;i<maxn;i++)if(res[i]>=cnt&&i!=a){b=i;break;}
	cout<<b;
}
