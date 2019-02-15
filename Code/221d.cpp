///with O(n sqrt n)
#include<bits/stdc++.h>
//#define int long long
#define S second
#define F first
using namespace std;
const int maxn=1e5+7,sqr=500;
int n,m,num[maxn],pos[sqr][maxn],HSH[maxn],HSh[maxn],t=1;
long long a[maxn];
int HASHC(int x){
	if(HSh[x])return HSh[x];
	HSh[x]=t;HSH[t]=x;t++;
	return t-1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)if(a[i]<maxn)num[a[i]]++;
	for(int i=1;i<=n;i++)if(a[i]<maxn&&num[a[i]]>=a[i])pos[HASHC(a[i])][i]++;
	
	for(int i=1;i<t;i++)for(int j=1;j<=n;j++)pos[i][j]+=pos[i][j-1];
	
	while(m--){
		int l,r,res=0;cin>>l>>r;
		for(int i=1;i<t;i++)if(pos[i][r]-pos[i][l-1]==HSH[i])res++;
		cout<<res<<'\n';
	}
}

///with O(nlogn)

#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxn=1e5+7,sqr=500;
int n,m,T[maxn],res[maxn],ind[maxn];
long long a[maxn];
map<int,vector<int> >pos;
pair<pair<int,int>,int>q[maxn];

void add(int x,int val){
	for(int i=x;i<maxn;i+=i&(-i))T[i]+=val;
}

int get(int x,int tmp=0){
	for(int i=x;i>0;i-=i&(-i))tmp+=T[i];
	return tmp;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ind[i]=pos[a[i]].size();
		pos[a[i]].push_back(i);
	}

	for(int i=0;i<m;i++)cin>>q[i].F.F>>q[i].F.S,q[i].S=i;
	sort(q,q+m);

	for(auto x:pos){
		if(x.S.size()>=x.F){
			add(x.S[x.F-1],1);
			if(x.F<x.S.size())add(x.S[x.F],-1);
		}
	}
	
	int lst=1;
	for(int i=0;i<m;i++){
		for(int j=lst;j<q[i].F.F;j++){
			if(ind[j]+a[j]<=pos[a[j]].size()){
				add(pos[a[j]][ind[j]+a[j]-1],-1);
				if(ind[j]+a[j]<pos[a[j]].size())add(pos[a[j]][ind[j]+a[j]],1);
				if(ind[j]+1+a[j]<=pos[a[j]].size()){
					add(pos[a[j]][ind[j]+a[j]],1);
					if(ind[j]+1+a[j]<pos[a[j]].size())add(pos[a[j]][ind[j]+1+a[j]],-1);
				}
			}
		}
		lst=q[i].F.F;
		res[q[i].S]=get(q[i].F.S);
	}
	
	for(int i=0;i<m;i++)cout<<res[i]<<endl;
}