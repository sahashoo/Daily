///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int d,n,m,x1[N],x2[N],y1[N],y2[N],cnt_l[N],cnt_r[N],cnt_u[N],cnt_d[N],cntl,cntr,cntu,cntd,ans=-1;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>d>>n>>m; 
	for(int i=1;i<=d;i++){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		if(x1[i]>x2[i])swap(x1[i],x2[i]);
		if(y1[i]>y2[i])swap(y1[i],y2[i]);
		cnt_d[y2[i]]++;
		cnt_u[y1[i]]++;
		cnt_l[x1[i]]++;
		cnt_r[x2[i]]++;
	}
	cin>>cntl>>cntr>>cntu>>cntd;
	for(int i=1;i<=n;i++)cnt_l[i]+=cnt_l[i-1];
	for(int i=n;i>=1;i--)cnt_r[i]+=cnt_r[i+1];
	for(int i=1;i<=m;i++)cnt_u[i]+=cnt_u[i-1];
	for(int i=m;i>=1;i--)cnt_d[i]+=cnt_d[i+1];
	for(int i=1;i<=d;i++)
		if(cnt_l[x2[i]-1]==cntl+(x1[i]!=x2[i])&&
		   cnt_r[x1[i]+1]==cntr+(x1[i]!=x2[i])&&
		   cnt_u[y2[i]-1]==cntu+(y1[i]!=y2[i])&&
		   cnt_d[y1[i]+1]==cntd+(y1[i]!=y2[i])){ans=i;}
	cout<<ans;
}
