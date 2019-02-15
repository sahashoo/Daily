///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
string s[5][5][5];

int finda(int x){
	if(x==1||x==4||x==7)return 1;
	if(x==2||x==5||x==8)return 2;
	if(x==3||x==6||x==9)return 3;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int j=1;j<=3;j++)
		for(int k=1;k<=3;k++)
			for(int i=1;i<=3;i++)
				cin>>s[i][j][k];
	
	int x,y,cnt=0;cin>>x>>y;
	int a=finda(y);
	int b=finda(x);
	for(int i=1;i<=3;i++)
	for(int j=0;j<3;j++)
		if(s[a][b][i][j]=='.')
			s[a][b][i][j]='!',cnt++;
	
	if(cnt==0){
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		for(int k=1;k<=3;k++)
		for(int t=0;t< 3;t++)
			if(s[i][j][k][t]=='.')
				s[i][j][k][t]='!';
	}
	
	for(int j=1;j<=3;j++){
		for(int k=1;k<=3;k++){
			for(int i=1;i<=3;i++){
				cout<<s[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
