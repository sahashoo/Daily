///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int k,n,a[maxn],sum[maxn],b[maxn];
set<int>st,res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>k>>n;
	for(int i=0;i<k;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=0;i<n;i++)cin>>b[i],st.insert(b[i]);
	sort(sum,sum+k);
	int mx=*st.rbegin();
	for(int i=k-1;i>=n-1;i--){
		int x=mx-sum[i];
		set<int>st2=st;
		for(int i=0;i<k;i++)st2.erase(x+sum[i]);
		if(st2.empty())res.insert(x);
	}
	cout<<res.size()<< endl;
}
