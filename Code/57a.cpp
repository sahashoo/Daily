///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int n,x1,x2,y2,y1;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>x1>>y1>>x2>>y2;

	if(x1==x2&&(x2==0||x2==n))return cout<<abs(y2-y1),0;
	
	if(y1==y2&&(y2==n||y2==0))return cout<<abs(x2-x1),0;

	if(abs(x1-x2)==n)return cout<<min(y1+n+y2,n-y1+n+n-y2),0;
	
	if(abs(y1-y2)==n)return cout<<min(x1+n+x2,n-x1+n+n-x2),0;

	if(y1==0&&x2==n)return cout<<n-x1+y2,0;
	
	if(y2==0&&x1==n)return cout<<n-x2+y1,0;
	
	if(y1==0&&x2==0)return cout<<x1+y2,0;
	
	if(y2==0&&x1==0)return cout<<x2+y1,0;

	if(y1==n&&x2==0)return cout<<n-y2+x1,0;
	
	if(y2==n&&x1==0)return cout<<n-y1+x2,0;

	if(y1==n&&x2==n)return cout<<n-x1+n-y2,0;
	
	if(y2==n&&x1==n)return cout<<n-x2+n-y1,0;
}
