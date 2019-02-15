///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a,b,c,p,sum,n;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b>>c;
	p=1;
	for(int i=1;i<n;i++){
		if(p==1){
			if(b<a)sum+=b,p=2;
			else sum+=a,p=3;
		}
		else if(p==2){
			if(b<c)sum+=b,p=1;
			else sum+=c,p=3;
		}
		else if(p==3){
			if(c<a)sum+=c,p=2;
			else sum+=a,p=1;
		}
	}
	cout<<sum;
}
