#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
const int SQ=320;
vector<pair<pair<int,int>,pair<int,int> > > bc[SQ];// {r,l},{k,id}
int res[MAXN],a[MAXN];

int32_t main(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<q;i++){
		int l,r,k;cin>>l>>r>>k;
		bc[l/SQ].push_back({{r,l},{k,i}});
	}
	for(int i=0;i<SQ;i++)
		sort(bc[i].begin(),bc[i].end());
	
	for(int i=0;i<SQ;i++){
		int l=SQ*i,r=SQ*i;// bucket start
		map<int,int>cnt;
		for(auto x:bc[i]){
			int L=x.F.F,R=x.F.S; // query
			while(l>L){
				l--;
				cnt[a[l]]++;
			}
			while(l<L){	
				cnt[a[l]]--;
				l++;
			}
			while(r<R){	
				cnt[a[r]]++;
				r++;
			}
			while(r>R){	
				r--;
				cnt[a[r]]--;
			}
			res[x.S.S]=cnt[x.S.F];
		}
	}
	
	for(int i=0;i<q;i++)cout<<res[i]<<'\n';
}