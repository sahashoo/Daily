///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
void null(){return ;}
const int maxn=1e6+7;

struct sgmntnode{int inc,dec,t4,t7,lzy;}sgmnt[maxn*2+(maxn/2)];
int n,q;
string s;

void build(int v=1,int l=0,int r=n-1){
	if(r==l)return sgmnt[v]={1,1,s[l]=='4',s[l]=='7'},null();
	int mid=l+r>>1;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	
	sgmnt[v].t4=sgmnt[v*2+1].t4+sgmnt[v*2].t4;
	sgmnt[v].t7=sgmnt[v*2+1].t7+sgmnt[v*2].t7;
	
	int INC=max(sgmnt[v*2].inc+sgmnt[v*2+1].t7,sgmnt[v*2].t4+sgmnt[v*2+1].inc);
	sgmnt[v].inc=max(INC,max(sgmnt[v].t4,sgmnt[v].t7));
	
	INC=max(sgmnt[v*2].dec+sgmnt[v*2+1].t4,sgmnt[v*2].t7+sgmnt[v*2+1].dec);
	sgmnt[v].dec=max(INC,max(sgmnt[v].t4,sgmnt[v].t7));
	
	return ;
}

void rvrs(sgmntnode &a){
	swap(a.inc,a.dec);
	swap(a.t4,a.t7);
	a.lzy^=1;
	return ;
}

void SendToChild(int v){
	if(sgmnt[v].lzy){
		rvrs(sgmnt[v*2]);
		rvrs(sgmnt[v*2+1]);
		sgmnt[v].lzy^=1;
	}
	return ;
}

void update(int L,int R,int v=1,int l=0,int r=n-1){
	if(r<L||l>R)return ;
	if(L<=l&&R>=r)return rvrs(sgmnt[v]);

	int mid=l+r>>1;
	SendToChild(v);
	update(L,R,v*2,l,mid);
	update(L,R,v*2+1,mid+1,r);
	
	sgmnt[v].t4=sgmnt[v*2+1].t4+sgmnt[v*2].t4;
	sgmnt[v].t7=sgmnt[v*2+1].t7+sgmnt[v*2].t7;
	
	int INC=max(sgmnt[v*2].inc+sgmnt[v*2+1].t7,sgmnt[v*2].t4+sgmnt[v*2+1].inc);
	sgmnt[v].inc=max(INC,max(sgmnt[v].t4,sgmnt[v].t7));
	
	INC=max(sgmnt[v*2].dec+sgmnt[v*2+1].t4,sgmnt[v*2].t7+sgmnt[v*2+1].dec);
	sgmnt[v].dec=max(INC,max(sgmnt[v].t4,sgmnt[v].t7));
	
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>q>>s;
	build();
	for(int i=0,l,r;i<q;i++){
		string a;
		cin>>a;
		if(a=="switch")cin>>l>>r,update(l-1,r-1);
		else cout<<sgmnt[1].inc<<'\n';	
	}
}