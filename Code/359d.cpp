///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=3e5+7;
int a[maxn],n,mx,nxt[maxn],bfr[maxn];
vector<int>res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bfr[i]=i-1;
		while(bfr[i]>0&&a[bfr[i]]%a[i]==0)bfr[i]=bfr[bfr[i]];
	}
	for(int i=n;i>=1;i--){
		nxt[i]=i+1;
		while(nxt[i]<=n&&a[nxt[i]]%a[i]==0)nxt[i]=nxt[nxt[i]];
	}
	for(int i=1;i<=n;i++){
		int mxi=nxt[i]-bfr[i]-2;
		if(mxi>mx)mx=mxi,res.clear();
		if(mxi==mx)res.push_back(bfr[i]+1);
	}
	sort(res.begin(),res.end());res.erase(unique(res.begin(),res.end()),res.end());
	cout<<res.size()<<" "<<mx<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
}
