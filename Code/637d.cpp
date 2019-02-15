///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
int n,m,s,d,a[maxn];
vector<pair<int,int> >res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[n-1]+1<m)res.push_back({0,m-a[n-1]-1});
	int last=a[n-1]+1;
	for(int i=n-2;i>=0;i--){
		if(a[i+1]-a[i]-2>=s&&a[i+1]-1+d>=last){
			res.push_back({1,last-a[i+1]+1});
			res.push_back({0,a[i+1]-a[i]-2});
			last=a[i]+1;
		}
	}
	if(a[0]-1>=s&&a[0]-1+d>=last){
		res.push_back({1,last-a[0]+1});
		res.push_back({0,a[0]-1});
	}
	else return cout<<"IMPOSSIBLE",0;
	for(int i=res.size()-1;i>=0;i--)cout<<(res[i].F?"JUMP ":"RUN ")<<res[i].S<<endl;
}
