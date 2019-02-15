#include<bits/stdc++.h>
#define size(a) (int)a.size()
using namespace std;
const int N=300;
int mxh,cnt;
vector<int>g[N];
map<string,int>mp;
bool mrk[N];

void mksml(string &s){
	for(int i=0;i<size(s);i++)if(s[i]<'a')s[i]=s[i]-'A'+'a';
}

void input(){
	int n;cin>>n;
	mp["polycarp"]=++cnt;
	for(int i=0;i<n;i++){
		string n1,n2,null;cin>>n1>>null>>n2;
		mksml(n1);
		mksml(n2);
		//cout<<"*********"<<n1<<"    "<<n2<<endl;;
		mp[n1]=++cnt;
		g[mp[n1]].push_back(mp[n2]);
		g[mp[n2]].push_back(mp[n1]);
	}
}

void dfs(int v,int h){
	mrk[v]=true;
	mxh=max(h,mxh);
	for(auto u:g[v])if(mrk[u]==false)dfs(u,h+1);
}

int32_t main(){
	input();
	dfs(1,1);
	cout<<mxh;
}