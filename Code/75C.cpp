///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
set<int>dd;

int gcd(int a,int b){return(b==0?a:gcd(b,a%b));}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,n;cin>>a>>b>>n;
    a=gcd(a,b);
    for(int i=1;i*i<=a;i++)
		if(a%i==0){
			dd.insert(i);
			if(i*i!=a)dd.insert(a/i);
		}
	while(n--){
        int l,r;cin>>l>>r;
		int tmp=*--dd.upper_bound(r);
		cout<<(l>tmp?-1:tmp)<<"\n";
    }
}