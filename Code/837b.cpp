#include<bits/stdc++.h>
using namespace std;
const int mxn=110;
int n,m,c[5];
bool mrk[256];
char a[mxn][mxn];

bool check(int r1,int r2,int c1,int c2){
	char c=a[r1][c1];
	for(int i=r1;i<r2;i++)for(int j=c1;j<c2;j++)if(a[i][j]!=c)return false;
	return true;
}

int32_t main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			mrk[a[i][j]]=true;
		}
	}
	if(mrk['R']&&mrk['G']&&mrk['B']){
		bool OK=false;
		if(n%3==0){
			OK=true;
			for(int i=0;i<3;i++)OK=OK&check(i*n/3,(i+1)*n/3,0,m);
			if(OK)return cout<<"YES",0;
		}
		if(m%3==0){
			OK=true;
			for(int i=0;i<3;i++)OK=OK&check(0,n,i*m/3,(i+1)*m/3);
			if(OK)return cout<<"YES",0;
		}
	}
	cout<<"NO";
}