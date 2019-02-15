#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,h1,a1,h2,a2,x1,y1,x2,y2,k1,t1,k2,t2;

int calc(int h,int a,int x,int y,int mod) {
	for(int i=1;i<=mod;++i){
        h=(h*x+y)%mod;
        if(h==a)return i;
    }
	return -1;
}

int32_t main(){
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	k1=calc(h1,a1,x1,y1,m);
	t1=calc(a1,a1,x1,y1,m);
	k2=calc(h2,a2,x2,y2,m);
	t2=calc(a2,a2,x2,y2,m);
	if(k1==-1||k2==-1)return cout<<-1,0;
	for(int i=0;i<=m*2;i++) {
		if(k1==k2)return cout<<k1,0;
		//if(t2==-1||t2==-1)return cout<<-2,0;
		if(k1<k2){
            if(t1==-1)return cout<<-1,0;
            k1+=t1;
        }
		else{
            if(t1==-1)return cout<<-1,0;
            k2+=t2;
		}
	}
	cout<<-1;
}
