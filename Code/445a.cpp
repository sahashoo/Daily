#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[150][150];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[i][j];
			if(s[i][j]=='.'){
				if((i+j)%2==0)cout<<"B"; else cout<<"W";
			}
			else cout<<s[i][j];
		}
		cout<<endl;
	}
}