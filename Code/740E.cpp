#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;

struct node{
	int ph,sh,pu,pd,su,sd,mx,l,r;
	long long vl,vr;
}seg[N*4];
int n;
long long lzy[N*4];

node merge(node a,node b)
{
	node ret;
	ret.l = a.l;
	ret.vl= a.vl;
	ret.r = b.r;
	ret.vr= b.vr;
	ret.pu= a.pu + ( a.pu==a.r-a.l && a.vr<b.vl ? b.pu:0);
	ret.pd= a.pd + ( a.pd==a.r-a.l && a.vr>b.vl ? b.pd:0);
	ret.su= b.su + ( b.su==b.r-b.l && a.vr<b.vl ? a.su:0);
	ret.sd= b.sd + ( b.sd==b.r-b.l && a.vr>b.vl ? a.sd:0);

	if(ret.pu==a.r-a.l)
		ret.ph = ret.pu + ( a.vr!=b.vl ? b.pd:0);
	else if(ret.pu<a.r-a.l)
		ret.ph = a.ph + ( a.ph==a.r-a.l && a.vr>b.vl ? b.pd:0);
	else 
		ret.ph = a.pu+b.ph;

	if(ret.sd==b.r-b.l)
		ret.sh = ret.sd + ( a.vr!=b.vl ?a.su:0);
	else if(ret.sd<b.r-b.l)
		ret.sh = b.sh + ( b.sh==b.r-b.l && a.vr<b.vl ? a.su:0);
	else
		ret.sh = b.sd+a.sh;

	ret.mx=0;
	if(b.vl>a.vr)
		ret.mx = max( ret.mx , b.ph+a.su );
	else if (a.vr>b.vl)
		ret.mx = max( ret.mx , a.sh+b.pd );
	
	ret.mx = max({ ret.mx , a.mx , b.mx , ret.ph , ret.sh });
	return ret;
}

void build(int l=0,int r=n,int v=1)
{
	seg[v].l=l;
	seg[v].r=r;
	seg[v].mx=1;
	seg[v].ph=1;
	seg[v].pu=1;
	seg[v].pd=1;
	seg[v].sh=1;
	seg[v].sd=1;
	seg[v].su=1;
	seg[v].vl=seg[v].vr=0;
	
	if(r-l<=1)
		return ;
	
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	build(l,mid,lc);
	build(mid,r,rc);
}

void shift(int v)
{
	int lc=v*2,rc=v*2+1;
	lzy[lc]+=lzy[v];
	lzy[rc]+=lzy[v];
	seg[lc].vl+=lzy[v];
	seg[lc].vr+=lzy[v];
	seg[rc].vl+=lzy[v];
	seg[rc].vr+=lzy[v];
	lzy[v]=0;
}

void upd(int s,int e,int x,int l=0,int r=n,int v=1)
{
	if(s<=l&&r<=e)
	{
		seg[v].vl+=x;
		seg[v].vr+=x;
		lzy[v]+=x;
		return; 
	}
	if (r<=s||e<=l)
		return ;
	
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	
	shift(v);
	upd(s,e,x,l,mid,lc);
	upd(s,e,x,mid,r,rc);
	
	seg[v]=merge(seg[lc],seg[rc]);
}

int main()
{	
	scanf("%d",&n);
	build();
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		upd(i,i+1,x);
	}
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int l,r,v;
		scanf("%d%d%d",&l,&r,&v);
		l--;
		upd(l,r,v);
		printf("%d\n",seg[1].mx);
	}
	
	return 0;
}