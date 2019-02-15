///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define size(a) (long long)a.size()
using namespace std;
const int maxn=1e5+7,INF=2e18+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;cin>>a>>b;
	int cnt=0;
	while(a>0&&b>0){
		if(a<b)swap(a,b);
		cnt+=a/b;
		a%=b;
	}
	cout<<cnt;
}
