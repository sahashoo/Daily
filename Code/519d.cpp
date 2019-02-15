#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int sum[maxn],chr[255];
string s;
map<int,int>F[255];

int32_t main(){
	for(int i='a',a=0;i<='z';i++)cin>>a,chr[i]=a;
	cin>>s;
	int n=s.size();
	int cnt=0,cur=0;
	for(int i=0;i<n;i++){
		if(F[s[i]].find(cur)!=F[s[i]].end())cnt+=F[s[i]][cur];
		cur+=chr[s[i]];
		F[s[i]][cur]++;
	}
	cout<<cnt;
}