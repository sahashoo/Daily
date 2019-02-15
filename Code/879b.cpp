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
int mx;
deque<int>Q;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0,x;i<n;i++)
		cin>>x,mx=max(x,mx),Q.push_back(x);
	if(k>n)return cout<<mx,0;
	int win=0,lst=-1,mn;
	while(win<k-1){
		int a=Q.front();Q.pop_front();
		int b=Q.front();Q.pop_front();
		mx=max(a,b);mn=min(a,b);
		if(mx==lst)win++;
		else win=0,lst=mx;
		Q.push_front(mx);Q.push_back(mn);
	}
	cout<<lst;
}
