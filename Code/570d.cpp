///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=5e5+7;
int n,m,In[maxn],Out[maxn],tim,A[30];
vector<int>g[maxn];
vector<pair<int,int> >H[maxn];
string s;
vector<string>ans;

void dfs(int v,int h){
	In[v]=++tim;
	H[h].push_back(make_pair(tim,H[h].back().S^A[s[v]-'a']));
	for(int i=0;i<g[v].size();i++)dfs(g[v][i],h+1);
	Out[v]=++tim;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)H[i].resize(1);
	for(int i=0;i<30;i++)A[i]=1<<i;
	for(int i=0;i<n-1;i++){
		int v;cin>>v;
		g[v-1].push_back(i+1);
	}
	cin>>s;
	dfs(0,0);
	for(int i=0;i<m;i++){
		int h,v;cin>>v>>h;v--,h--;
		int l=lower_bound(H[h].begin(),H[h].end(),make_pair(In[v],-1))-H[h].begin()-1;
		int r=lower_bound(H[h].begin(),H[h].end(),make_pair(Out[v],-1))-H[h].begin()-1;
		int t=H[h][l].S^H[h][r].S;
		bool OK= t - (t & -t);
		if(!OK)ans.push_back("Yes");
		else   ans.push_back("No");
	}
	for(auto x:ans)cout<<x<<endl;
}

///guni solution
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=5e5+7;
bool ans[MAXN],t[MAXN][26],big[MAXN];
int cnt[MAXN],h[MAXN],sz[MAXN];
vector<int>g[MAXN];
vector<pair<int,int> >q[MAXN];
string s;

void getsize(int v){
	sz[v]=1;
	for(int u:g[v]){
		h[u]=h[v]+1;
		getsize(u);
		sz[v]+=sz[u];
	}
}

void add(int v,int x){
	cnt[h[v]]-=t[h[v]][s[v]-'a'];
	t[h[v]][s[v]-'a']^=1;
	cnt[h[v]]+=t[h[v]][s[v]-'a'];
	for(int u:g[v])
		if(big[u]==false)
			add(u,x);
}

void dfs(int v,bool kp){
	int mx=0,bc=-1;
	for(int u:g[v])
		if(mx>sz[u])
			mx=sz[u],bc=u;
	
	if(mx)big[bc]=1;
	for(int u:g[v])
		dfs(u,u==bc);
	
	add(v,1);
	for(pair<int,int>x:q[v])
		ans[x.S]=(cnt[x.F]<=1);
	if(mx)big[bc]=0;
	if(kp==false)add(v,-1);
}


int main(){
	int n,m,v,h;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d",&v);
		g[v-1].push_back(i);
	}
	getsize(0);
	cin>>s;
	for(int i=0;i<m;i++){
		scanf("%d%d",&v,&h);
		q[v-1].push_back({h-1,i});
	}
	dfs(0,0);
	for(int i=0;i<m;i++){
		ans[i]?printf("Yes\n"):printf("No\n");
	}
}