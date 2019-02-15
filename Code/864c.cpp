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

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,f,k;cin>>a>>b>>f>>k;
	if(f>b)return cout<<-1,0;
	int tot=b,p=0,res=0;
	for(int i=0;i<k;i++){
		if(p==0){
			p=a;
			tot-=f;
			if(tot<0)return cout<<-1,0;
			if(i==k-1){
				if(tot<a-f)tot=b,res++;
				if(a-f>tot)return cout<<-1,0;
			}
			else{
				if(2*(a-f)>tot)tot=b,res++;
				if(2*(a-f)>tot)return cout<<-1,0;
			}
			tot-=a-f;
		}
		else if(p==a){
			p=0;
			tot-=a-f;
			if(tot<0)return cout<<-1,0;
			if(i==k-1){
				if(tot<f)tot=b,res++;
				if(f>tot)return cout<<-1,0;
			}
			else{
				if(2*f>tot)tot=b,res++;
				if(2*f>tot)return cout<<-1,0;
			}
			tot-=f;
		}
	}
	cout<<res;
}
