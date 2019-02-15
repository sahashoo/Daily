#include<bits/stdc++.h>
using namespace std;
string s[4];

bool check(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(j+2<4&&s[i][j]=='x'&&s[i][j+1]=='x'&&s[i][j+2]=='x')return true;
			if(i+2<4&&s[i][j]=='x'&&s[i+1][j]=='x'&&s[i+2][j]=='x')return true;
			if(i+2<4&&j+2<4&&s[i][j]=='x'&&s[i+1][j+1]=='x'&&s[i+2][j+2]=='x')return true;
			if(i+2<4&&j-2>=0&&s[i][j]=='x'&&s[i+1][j-1]=='x'&&s[i+2][j-2]=='x')return true;
		}
	} 
	return false;
}

int main(){
	for(int i=0;i<4;i++)cin>>s[i];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='.'){
				s[i][j]='x';
				if(check()){cout<<"YES";return 0;}
				s[i][j]='.';
			}
		}
	}
	cout<<"NO";
}