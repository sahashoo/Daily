#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int n,k,lst[300],fst[300];
string s;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(fst,MOD,sizeof(fst));
	memset(lst,-1,sizeof(lst));
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)lst[s[i]]=max(i,lst[s[i]]),fst[s[i]]=min(fst[s[i]],i);
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j='A';j<='Z';j++){
			if(lst[j]!=-1){
				if(lst[j]>=i&&fst[j]<=i)cnt++;
			}
		}
		if(cnt>k)return cout<<"YES",0;
	}
	cout<<"NO";
}
