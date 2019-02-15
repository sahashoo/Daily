///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
const int maxn=2e6+7,INF=1e9+7;
int x;
vector<pair<int,int> >res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>x;x*=6;
	for(int n=1;n<maxn;n++){
		int sumi=(n+1)*n;
		if(x%sumi==0){
			int rich=x/sumi+n-1,m;
			if(rich%3==0){
				m=rich/3;
				if(n<=m){
					res.push_back({n,m});
					if(n!=m)res.push_back({m,n});
				}
			}
		}
	}
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x.F<<" "<<x.S<<endl;
}