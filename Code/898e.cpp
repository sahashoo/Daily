///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
int dif[MAXN],cnt,zro,sqr,res;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,a;i<n;i++){
		cin>>a;
		int x=sqrt(a);
		if(a==0)zro++;
		else if(x*x!=a)
			dif[cnt++]=min(a-(x*x),(x+1)*(x+1)-a);
		else sqr++;
	}
	sort(dif,dif+cnt);
	for(int i=0;i<n/2-zro-sqr;i++)res+=dif[i];
	if(sqr+zro <= n/2)
		cout<<res;
	else
		cout<<sqr+((zro<=n/2?1:2)*(zro-n/2));
}
