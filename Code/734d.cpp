#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
int n,xs,ys;
bool ans;
pair<pair<int,int>,char>a[10];

int fas(int x2,int y2){return max(abs(xs-x2),abs(ys-y2));}

int dir(int x,int y){

	if(x==xs&&y<ys)return 1;
	if(x==xs&&y>ys)return 2;
	
	if(y==ys&&x<xs)return 3;
	if(y==ys&&x>xs)return 4;
	
	if(y-ys==x-xs&&x<xs)return 5;
	if(y-ys==x-xs&&x>xs)return 6;
	if(y-ys==xs-x&&y>ys)return 8;
	if(y-ys==xs-x&&y<ys)return 7;
	return 0;
}

int32_t main(){
	cin>>n>>xs>>ys;
	for(int i=0;i<10;i++)a[i].S='*';
	for(int i=0;i<n;i++){
		char t;int x,y;
		cin>>t>>x>>y;
		int smt=dir(x,y);
		if(a[smt].S=='*'||fas(x,y)<fas(a[smt].F.F,a[smt].F.S))a[smt]={{x,y},t};
	}
	for(int i=1;i<=4;i++)if(a[i].S=='R'||a[i].S=='Q')ans=true;
	for(int i=5;i<=8;i++)if(a[i].S=='B'||a[i].S=='Q')ans=true;
	cout<<(ans?"YES":"NO");
}