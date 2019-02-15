//kamtar besozon
#include <bits/stdc++.h>
using namespace std;
string a,b,c;
int t[105],dp[105][105][105],sa,sb,sc;

void kmp(){
	int i=0,j=-1;
	t[0]=-1;
	for(i=1;i<sc;i++){
		while(j>=0&&c[i-1]!=c[j])j=t[j];
		j++;
		t[i]=j;
	}
}

int cek(int p,int r){
	while(r>=0&&a[p]!=c[r])r=t[r];
	return r;
}

int lcs(int p,int q,int r){
	if(r==sc)return -1000;
	if(p==sa||q==sb)return 0;
	if(dp[p][q][r]!=-1)return dp[p][q][r];
	dp[p][q][r]=max(lcs(p+1,q,r),lcs(p,q+1,r));
	if(a[p]==b[q])dp[p][q][r]=max(dp[p][q][r],1+lcs(p+1,q+1,cek(p,r)+1));
	return dp[p][q][r];
}

int main(){
	cin>>a>>b>>c;
	sa=a.size();
	sb=b.size();
	sc=c.size();
	kmp();
	memset(dp,-1,sizeof(dp));
	int ans=lcs(0,0,0);
	if(ans==0)return cout<<"0",0;
	int p=0,q=0,r=0;
	while(ans>0){
		int gg=cek(p,r)+1;
		int t1=lcs(p+1,q,r),t2=lcs(p,q+1,r),t3=(a[p]==b[q]?1+lcs(p+1,q+1,gg):-1000);
		if(t1>=t2&&t1>=t3)p++;
		else{
			if(t2>=t1&&t2>=t3)q++;
			else{cout<<a[p++];q++;r=gg;ans--;}
		}
	}	
}