///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int p[maxn],cnt;
bool mrk[maxn];

void dfs(int v){
	cnt++;
	mrk[v]=true;
	if(mrk[p[v]]==false)dfs(p[v]);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	vector<int>col;
	for(int i=1;i<=n;i++)
		if(mrk[i]==false)
			cnt=0,dfs(i),col.push_back(cnt);
	sort(col.begin(),col.end());
	if(col.size()>=2)
		col[col.size()-2]+=col.back(),col.pop_back();
	int conv=0;
	for(auto x:col)conv+=x*x;
	cout<<conv;
}
