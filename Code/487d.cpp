#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+9;
const int MAXM=12;
const int SQ=320;
int qx[MAXN][MAXM],qy[MAXN][MAXM],n,m,q;
char tbl[MAXN][MAXM];

bool valid(int x,int y){
	return (x<n && y<m && x>=0 && y>=0);
}

void calc(int l,int r){
	
	for(int i=l;i<r;i++) 
		for(int j=0;j<m-1;j++)
			if(tbl[i][j]=='>'&&tbl[i][j+1]=='<'){
				qx[i][j]=-2;
				qx[i][j+1]=-2;
				qy[i][j]=-2;
				qy[i][j+1]=-2;
			}
			
	for(int i=l;i<r;i++){
		for(int j=0;j<m;j++)
			if(tbl[i][j]=='^'){
				if(i!=l){
					qx[i][j]=qx[i-1][j];
					qy[i][j]=qy[i-1][j];
				}
				else{
					qx[i][j]=i-1;
					qy[i][j]=j;
				}
			}
		for(int j=0;j<m;j++) 
			if(tbl[i][j]=='<'){
				if(j){
					qx[i][j]=qx[i][j-1];
					qy[i][j]=qy[i][j-1];
				}
				else{
					qx[i][j]=i;
					qy[i][j]=-1;
				}
			}
		for(int j=m-1;j>=0;j--)
			if(tbl[i][j]=='>'){
				if(j!=m-1){
					qx[i][j]=qx[i][j+1];
					qy[i][j]=qy[i][j+1];
				}
				else{
					qx[i][j]=i;
					qy[i][j]=m;
				}
			}
	}
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>tbl[i][j];
		
	for(int i=0;i<n;i+=SQ)
		calc(i,min(n,i+SQ));
	
	while(q--){	
		char c;cin>>c;
		if(c=='A'){
			int px,py,tx,ty;
			cin>>px>>py;
			px--,py--;
			while(valid(px,py)){
				tx=qx[px][py];
				ty=qy[px][py];
				px=tx;
				py=ty;
			}
			cout<<px+1<<" "<<py+1<<'\n';
		}
		else{
			int px,py;
			cin>>px>>py>>c;
			px--,py--;
			tbl[px][py]=c;
			calc((px/SQ)*SQ,(px/SQ+1)*SQ);
		}
	}
}