#include<bits/stdc++.h>
using namespace std;
pair<string,string> ss;
map<string,string> st;
string str[3500],op[3500];
int n,m;

void input(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>ss.first>>ss.second;
		if(ss.first.size() <= ss.second.size()){
			st[ss.first]=ss.first;
		}
		else{
			st[ss.first]=ss.second;
		}
	}
	for(int i=0;i<n;i++){
		cin>>str[i];
		op[i]=st[str[i]];
	}
}

int main(){
	input();
	for(int i=0;i<n;i++){
		cout<<op[i]<<" ";
	}
}