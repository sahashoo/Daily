///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int s,x1,x2,t1,t2,p,d;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	if(x1>x2)x1=s-x1,x2=s-x2,p=s-p,d*=-1;
	int tmp=0;
	if(p<=x1&&d==1)tmp=(x2-p)*t1;
	else if(d==1)tmp=(2*s+x2-p)*t1;
	else tmp=(p+x2)*t1;
	cout<<min(tmp,(x2-x1)*t2);
}
