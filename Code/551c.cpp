///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int n,m,a[maxn],res,cnt,b[maxn];

bool OK(int x){
	for(int i=0;i<=n;i++)b[i]=a[i];
	int cur=n;
	for(int i=0;i<m;i++){
		while(cur>0&&b[cur]==0)cur--;
		if(cur==0)return true;
		int cnt=x;
		if(cnt<cur)return false;
		cnt-=cur;
		while(cur>0&&cnt){
			int mn=min(cnt,b[cur]);
			cnt-=mn;b[cur]-=mn;
			if(b[cur]==0)cur--;
		}
	}
	while(cur>0&&b[cur]==0)cur--;
	return cur<1;
}

void BS(int l,int r){
	if(l>r)return ;
	int mid=(l+r)/2;
	if(OK(mid)){res=mid;return BS(l,mid-1);}
	else return BS(mid+1,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	BS(0,INF);
	cout<<res;
}
