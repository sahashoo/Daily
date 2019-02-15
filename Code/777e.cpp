///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
const int maxn=1e5+7;
int n,ans,h[maxn],tree[maxn];
pair<pair<int,int>,int>p[maxn];
vector<int>arr;

int c(int x,int mx=0){for(x=x+1;x>0;x-=x&(-x))mx=max(mx,tree[x]);return mx;}
void update(int i,int val){for(i=i+1;i<=arr.size();i+=i&(-i))tree[i]=max(val,tree[i]);}

int32_t main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].F.S>>p[i].F.F>>h[i];
		p[i].S=i;
		arr.push_back(p[i].F.S);
	}
	sort(arr.begin(),arr.end());
	arr.resize(unique(arr.begin(),arr.end())-arr.begin());
	sort(p,p+n,greater<pair<pair<int,int>,int> >());
	for(int i=0;i<n;i++){
		int k=lower_bound(arr.begin(),arr.end(),p[i].F.F)-arr.begin();
		int sum=c(k-1)+ h[p[i].S];
		k=lower_bound(arr.begin(),arr.end(),p[i].F.S)-arr.begin();
		update(k,sum);
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}