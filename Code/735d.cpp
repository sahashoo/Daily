#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,m,mrk=-1,a[maxn],b[maxn];

bool check(int r){
	if(m>r)return false;
	int cnt=0,cnt1=0;
	bool mark[maxn];
	stack<int> s;
	for(int i=0;i<maxn;i++)mark[i]=false;
	for(int i=r;i>=1;i--){
		if(mark[a[i]]==false&&a[i]!=0){
			mark[a[i]]=true;
			cnt++;
			s.push(i);
		}
	}
	if(cnt==m){
		while(s.size()){
			int y=s.top();int x=a[y];
			s.pop();
			if(y-1-b[x]-cnt1>=0)cnt1+=b[x]+1;
			else return false;
		}
		return true;
	}
	return false; 
}

void bs(int l,int r){
	if(l==r){
		if(check(l))cout<<l;
		else cout<<mrk;
		return ;
    }
	int mid=(l+r)/2;
	if(check(mid)){
      mrk=mid;
      bs(l,mid);
    }
	else bs(mid+1,r);
}

int32_t main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	bs(1,n);
}