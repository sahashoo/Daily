#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
int n,m,a[maxn];
deque<pair<int,int> >dq;
deque<int>ary;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++){
		int r,t;cin>>t>>r;r--;
		while(dq.size()&&dq.front().F<=r)dq.pop_front();
		dq.push_front(make_pair(r,t));
	}
	dq.push_front(make_pair(-1,0));
	sort(a,a+dq.back().F+1);
	for(int i=0;i<=dq.back().F;i++)ary.push_front(a[i]);	
	while(dq.size()>1){
		pair<int,int>x=dq.back();dq.pop_back();
		if(x.S==2)for(int i=x.F;i>dq.back().F;i--)a[i]=ary.back(),ary.pop_back();
		else for(int i=x.F;i>dq.back().F;i--)a[i]=ary.front(),ary.pop_front();
	}
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
}
