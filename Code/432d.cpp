#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
string s;
int cnt[maxn],z[maxn];
bool mrk[maxn];
vector<pair<int,int> > res;

int32_t main(){
	cin>>s;
	cnt[s.size()]++;mrk[s.size()]=true;
	int r=-1,l=-1;
	for(int i=1;i<s.size();i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<s.size()&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r){l=i;r=i+z[i]-1;}
		if(i+z[i]==s.size())mrk[z[i]]=true;
		cnt[z[i]]++;
	}
	for(int i=s.size()-1;i>-0;i--)cnt[i]+=cnt[i+1];
	for(int i=1;i<=s.size();i++)if(mrk[i])res.push_back({i,cnt[i]});
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i].q<<" "<<res[i].w<<endl;
}
