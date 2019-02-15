#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,m,a[maxn],sgmnt[maxn*10],siz;

bool build(int ind=1,int l=0,int r=siz-1){
	if(l==r)return sgmnt[ind]=a[l],false;
	int mid=l+r>>1;
	bool a=build(ind*2,l,mid);
	build(ind*2+1,mid+1,r);
	if(a==true){
		sgmnt[ind]=sgmnt[ind*2]^sgmnt[ind*2+1];
		return false;
	}
	else{
		sgmnt[ind]=sgmnt[ind*2]|sgmnt[ind*2+1];
		return true;
	}
}

int update(int val,int id,int ind=1,int l=0,int r=siz-1){
	if(id<l||id>r)return -1;
	if(r==l)return sgmnt[ind]=val,0;
	int mid=l+r>>1;
	int a=update(val,id,ind*2,l,mid);
	int b=update(val,id,ind*2+1,mid+1,r);
	if(a==1||b==1)return sgmnt[ind]=sgmnt[ind*2]^sgmnt[ind*2+1],0;
	if(a==0||b==0)return sgmnt[ind]=sgmnt[ind*2]|sgmnt[ind*2+1],1;

}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;siz=pow(2,n);
	for(int i=0;i<siz;i++)cin>>a[i];
	build();
//	output();cout<<endl;
	for(int i=1;i<=m;i++){
		int b,p;cin>>p>>b;p--;
		//cout<<"............."<<p<<" "<<b<<endl;
		a[p]=b;
		update(b,p);
		cout<<sgmnt[1]<<'\n';
	}
}