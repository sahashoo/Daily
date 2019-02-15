#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int arr[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	string s;cin>>s;
	for(int i=0;i<n;i++)arr[s[i]]++;
	for(int i='a';i<='z';i++)if(arr[i]>k)return cout<<"NO",0;
	cout<<"YES";
}