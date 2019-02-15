#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=2e5+7;
int val[MAXN],pos[MAXN];
pair<int,int>a[MAXN];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i].F,a[i].S=i;
	
	sort(a,a+n);
	for(int i=0;i<n;i++)
		pos[a[i].S]=i;
	for(int i=0;i<n;i++)
		val[i]=a[i].F;
	
	while(m--){
		int x,len;cin>>x>>len;
		int p1=pos[x-1];
		int dir=1;
		int dis=val[p1]+len*dir;
		int p2=upper_bound(val,val+n,dis)-val-1;
        len-=abs(val[p1]-val[p2]);
        p1=p2;
        dir*=-1;
        while(true){
            dis=val[p1]+len*dir;
            if(dir==1)
				p2=upper_bound(val,val+n,dis)-val-1;
			else 
				p2=lower_bound(val,val+n,dis)-val;
			if(p1==p2)break;
			int temp=abs(val[p1]-val[p2]);
			if((len/temp)&1==1)
				dir*=-1,p1=p2;
			len%=temp;
        }
		cout<<a[p1].S+1<<'\n';
	}
	
}