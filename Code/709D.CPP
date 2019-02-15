#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	if(a+b+c+d==0)return cout<<0,0;
	int i=1,aa=0,dd=0,cnt=0;
	while(true){
		int sum=i*(i-1)/2;
		if(sum==a)aa=i,cnt++;
		if(sum==d)dd=i,cnt++;
		if(cnt==2)break;
		if(sum>max(a,d))return cout<<"Impossible",0;
		i++;
	}
	if(a+c+b==0)aa=0;
	if(d+c+b==0)dd=0;
	if(b+c==aa*dd){
		cnt=aa+dd;
		while(cnt--){
			if(b>=dd)cout<<0,b-=dd,aa--;
			else cout<<1,dd--;
		}
	}
	else cout<<"Impossible";
}
