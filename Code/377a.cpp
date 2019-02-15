#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
string s[550];
void dfs(int i, int j) {
	s[i][j]= '.';
	if(i+1<n&&s[i+1][j]=='m') dfs(i+1,j);
	if(j+1<m&&s[i][j+1]=='m') dfs(i,j+1);
	if(i-1>=0&&s[i-1][j]=='m') dfs(i-1,j);
	if(j-1>=0&&s[i][j-1]=='m') dfs(i,j-1);
	if(k){s[i][j]='X';k--;}
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(s[i][j]=='.'){s[i][j]='m';x=i;y=j;}
    dfs(x,y);
    for(int i=0;i<n;i++) cout<<s[i]<<endl;
}