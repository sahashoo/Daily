///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,k,arr[maxn],ans;
string s;

int ARR(int i){
	if(i<0)return 0;
	if(i>=n)return arr[n-1];
	return arr[i];
}

bool check(int l){
	for(int i=0;i<n;i++)if(s[i]=='0'&&(ARR(i-1)-ARR(i-l-1)+ARR(i+l)-ARR(i))>=k)return true;
	return false;
}

void bs(int l,int r){
	if(l>r)return ;
	int mid=(l+r)/2;
	if(check(mid)){ans=mid;bs(l,mid-1);}
	else bs(mid+1,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')arr[i]++;
		if(i)arr[i]+=arr[i-1];
	}
	bs(1,n);
	cout<<ans;
}
