#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
const int INF=3e18+7;
int a[MAXN],mn=INF;
vector<int>pos;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],mn=min(a[i],mn);
	for(int i=0;i<n;i++)
		if(a[i]==mn)pos.push_back(i);
	mn=INF;
	for(int i=1;i<=pos.size();i++)
		mn=min(mn,abs(pos[i]-pos[i-1]));
	cout<<mn;
}
