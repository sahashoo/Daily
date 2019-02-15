#include<bits/stdc++.h>
#define null_mapped_type null_type
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

struct seg{
	int l,r;
	seg(const int &l,const int &r):l(l),r(r){}
	bool operator < (const seg& a) const {
		return (r-l>a.r-a.l)||(r-l==a.r-a.l&&r>a.r);
	}
};
set<seg>st;
indexed_set ist;
map<int,int>mp;
int n;

void del(int x){
	int p=mp[x],pl,pr;
	auto it=ist.find(p);
	auto itl=it,itr=it;
	if(itl==ist.begin())pl=1;
	else itl--,pl=(*itl)+1;//
	itr++;
	if(itr==ist.end())pr=n;
	else pr=(*itr)-1;
	st.erase(seg(pl,p-1));
	st.erase(seg(p+1,pr));
	st.insert(seg(pl,pr));
	ist.erase(p);
	mp.erase(x);
	return ;
}
void add(int x){
	seg a=(*st.begin());
	st.erase(a);
	int l=a.l,r=a.r,mid=(l+r+1)/2;
	ist.insert(mid);
	mp[x]=mid;
	st.insert(seg(l,mid-1));
	st.insert(seg(mid+1,r));
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;cin>>n>>q;
	st.insert(seg(1,n));
	ist.clear();
	while(q--){
		int x;cin>>x;
		if(x==0){
			int l,r;cin>>l>>r;
			int temp=ist.order_of_key(r+1);
			temp-=ist.order_of_key(l);
			cout<<temp<<'\n';
			continue;
		}
		if(mp.count(x))del(x);
		else add(x);
	}
}
