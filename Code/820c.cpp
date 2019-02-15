///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int a,b,l,r,c,pl,pr,cl,cr;
	
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>l>>r,c=a+b;
	cl=--l/c;pl=l%c;
	cr=--r/c;pr=r%c;
	if(cl==cr)cout<<min(r-l+1,max(a-pl,1));
	else if(a<=b){
		if(cl<cr-1)cout<<a+1;
		else{
			int x=max(1,a-pl);
			int y=min(a,pr+1);
			cout<<min(a,x+y)+(y==a);
		}
	}
	else{
		int d=a-b;
		if(cl==cr-1)cout<<max(1,min(d,a-pl))+min(a,pr+1);
		else if(cl==cr-2)cout<<a+max(1,d+min(0,pr-a+1+max(0,a-pl)));
		else cout<<a+d;
	}
}
