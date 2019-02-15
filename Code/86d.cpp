///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
const int sqN=450;
int l,r,cnt[maxn*10],a[maxn];
long long res[maxn],cur;
pair<pair<int,int>,int>q[maxn];

bool cmp(pair<pair<int,int>,int>p,pair<pair<int,int>,int>q){
	if(p.F.F/sqN==q.F.F/sqN)
		return (p.F.S<q.F.S)^((p.F.F/sqN)%2);
	return p.F.F<q.F.F;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t;cin>>n>>t;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<t;i++)cin>>l>>r,q[i]={{l-1,r},i};
	sort(q,q+t,cmp);
	l=0,r=0;
	for(int i=0;i<t;i++){
		int L=q[i].F.F,R=q[i].F.S;
		while(l>L){
			l--;
			cur-=1LL*a[l]*cnt[a[l]]*cnt[a[l]];
			cnt[a[l]]++;
			cur+=1LL*a[l]*cnt[a[l]]*cnt[a[l]];
		}
		while(l<L){	
			cur-=1LL*a[l]*cnt[a[l]]*cnt[a[l]];
			cnt[a[l]]--;
			cur+=1LL*a[l]*cnt[a[l]]*cnt[a[l]];
			l++;
		}
		while(r<R){	
			cur-=1LL*a[r]*cnt[a[r]]*cnt[a[r]];
			cnt[a[r]]++;
			cur+=1LL*a[r]*cnt[a[r]]*cnt[a[r]];
			r++;
		}
		while(r>R){	
			r--;
			cur-=1LL*a[r]*cnt[a[r]]*cnt[a[r]];
			cnt[a[r]]--;
			cur+=1LL*a[r]*cnt[a[r]]*cnt[a[r]];
		}
		res[q[i].S]=cur;
	}
	for(int i=0;i<t;i++)cout<<res[i]<<'\n';
}