#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
vector<int> g[maxn],ans;
string s[maxn];
int n;
bool mrk[maxn],use[maxn];

void dfs(int v){
	mrk[v]=true;
	use[v]=true;
	for(int i=0;i<g[v].size();i++){
        int u=g[v][i];
		if(use[u]){cout<<"Impossible";exit(0);}
		if(mrk[u]==false&&use[u]==false)dfs(u);
	}
	use[v]=false;
	ans.push_back(v);
}

void graph(int id){
	for(int i=0;i<min(s[id].size(),s[id+1].size());i++){
		if(s[id][i]!=s[id+1][i]){
			g[s[id+1][i]-'a'].push_back(s[id][i]-'a');
			return ;
		}
	}
	if(s[id].size()>s[id+1].size()){cout<<"Impossible";exit(0);}
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<n;i++)graph(i);
	for(int i=0;i<26;i++)if(mrk[i]==false)dfs(i);
	for(int i=0;i<26;i++){char c=ans[i]+'a';cout<<c;}
}
