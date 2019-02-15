///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,a[maxn];
vector<int>ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=30;i++){
		int TotalAND=(1<<30)-1;
		vector<int>cur;cur.clear();
		for(int j=0;j<n;j++)if(a[j]&(1<<i))cur.push_back(a[j]),TotalAND&=a[j];
		if(TotalAND%(1<<i)==0)ans=cur;
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x<<" ";
}
