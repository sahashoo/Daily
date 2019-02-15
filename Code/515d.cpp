///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define PAIR pair<int,int>
using namespace std;
const int maxn=2007;
int n,m;
char a[maxn][maxn];
queue<PAIR>Q;

void F(PAIR id1,PAIR id2){
	if(id1.F==id2.F){
		if(id1.S>id2.S)a[id1.F][id1.S]='>',a[id2.F][id2.S]='<';
		if(id1.S<id2.S)a[id1.F][id1.S]='<',a[id2.F][id2.S]='>';
	}
	if(id1.S==id2.S){
		if(id1.F>id2.F)a[id1.F][id1.S]='v',a[id2.F][id2.S]='^';
		if(id1.F<id2.F)a[id1.F][id1.S]='^',a[id2.F][id2.S]='v';
	}
}

int deg(PAIR id){
	int deg=0;
	if(a[id.F+1][id.S]=='.')deg++;
	if(a[id.F-1][id.S]=='.')deg++;
	if(a[id.F][id.S+1]=='.')deg++;
	if(a[id.F][id.S-1]=='.')deg++;
	return deg;
}

PAIR E(PAIR id){
	PAIR e={-1,-1};
	if(a[id.F+1][id.S]=='.')e={id.F+1,id.S};
	if(a[id.F-1][id.S]=='.')e={id.F-1,id.S};
	if(a[id.F][id.S+1]=='.')e={id.F,id.S+1};
	if(a[id.F][id.S-1]=='.')e={id.F,id.S-1};
	return e;
}

bool CC(PAIR cc){
	if(a[cc.F][cc.S]=='.')return true;
	return false;
}

void PlusQ(PAIR c){
	if(deg({c.F+1,c.S})==1&&CC({c.F+1,c.S}))Q.push({c.F+1,c.S});
	if(deg({c.F-1,c.S})==1&&CC({c.F-1,c.S}))Q.push({c.F-1,c.S});
	if(deg({c.F,c.S+1})==1&&CC({c.F,c.S+1}))Q.push({c.F,c.S+1});
	if(deg({c.F,c.S-1})==1&&CC({c.F,c.S-1}))Q.push({c.F,c.S-1});
}

int32_t main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(deg({i,j})==1&&a[i][j]=='.')Q.push({i,j});
		}
	}
	while(Q.size()){
		PAIR c=Q.front();Q.pop();
		PAIR e=E(c);
		if(e.F!=-1)F(c,e);
		PlusQ(c);PlusQ(e);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.')return cout<<"Not unique",0;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
