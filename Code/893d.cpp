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
	int n,d;cin>>n>>d;
	int cur=0,lst=INF,res=0;
	for(int i=0,x;i<n;i++){
		cin>>x;
		cur+=x;
		lst=max(lst,cur);
		if(x==0&&cur<0){
			if(lst-cur<=d)
				lst-=cur,cur=0;
			else res++,cur=lst=0;
		}
		if(cur>d)return cout<<-1,0;
	}
	cout<<res;
}
