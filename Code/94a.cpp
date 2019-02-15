#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;

int32_t main(){
	string s;cin>>s;
	for(int i=0;i<10;i++){
		string d;cin>>d;
		mp[i]=d;
	}
	string str="",ans="";
	for(int i=1;i<=80;i++){
		str+=s[i-1];
		if(i%10==0){
			for(int j=0;j<10;j++){
				if(mp[j]==str){
					cout<<j;
					str="";
					break;
				}
			}
		}
	}
}