#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
int go[]={0,1,2,3};
char a[100][100];
int n,m,Y,X;
string s;

inline int cn(char x){
	return (int)(x-'0');
}

bool check(){
	int x=X,y=Y;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		x+=dx[go[cn(c)]],y+=dy[go[cn(c)]];
		if(x>=n||y>=m)return false;
		if(x<0||y<0)return false;
		if(a[x][y]=='#')return false;
		if(a[x][y]=='E')return true;
	}
	if(a[x][y]=='E')return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='S')X=i,Y=j;
		}
	}
	cin>>s;
	int cnt=0;
	do{
		bool tmp=check();
		cnt+=(tmp?1:0);
	}while(next_permutation(go,go+4));
	cout<<cnt;
}
