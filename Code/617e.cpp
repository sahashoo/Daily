#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
const int MAXM=1e7+7;
const int SQ=320;
int cnt[MAXM],prf[MAXN],a[MAXN],ans[MAXN],res,k;
vector<vector<pair<pair<int,int>,int> > >q;

bool cmp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
	return a.F.S<b.F.S;
}

void add(int a){
	res+=cnt[a^k];
	cnt[a]++;
}

void del(int a){
	cnt[a]--;
	res-=cnt[a^k];
}

int32_t main(){
	
	int n,m;cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i],prf[i+1]=prf[i]^a[i];
	
	q.resize(n/SQ+2);
	for(int i=0;i<m;i++){
		int l,r;cin>>l>>r;
		l--,r++;
		q[l/SQ].push_back({{l,r},i});
	}
	for(auto &x:q)
		sort(x.begin(),x.end(),cmp);
	
	for(int i=0;i<q.size();i++){
		int l,r;l=r=i*SQ;
		for(const auto &x:q[i]){
			while(r<x.F.S){
				add(prf[r]);
				r++;
			}
			while(l<x.F.F){
				del(prf[l]);
				l++;
			}
			while(l>x.F.F){
				l--;
				add(prf[l]);
			}
			ans[x.S]=res;
        }
		for(int j=l;j<r;j++)
			del(prf[j]);
    }
	
	for(int i=0;i<m;i++)
		cout<<ans[i]<<'\n';
	
}