#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
//map<int,queue<int> >pos;
bool mrk[maxn];
stack<int>pos;

int type(char c){
	if(c=='('||c==')')return 1;
	if(c=='<'||c=='>')return 2;
	if(c=='['||c==']')return 3;
	if(c=='{'||c=='}')return 4;
}

bool kind(char c){
	if(c=='>'||c==']'||c==')'||c=='}')return true;
	return false;
}

int32_t main(){
	string s;cin>>s;
	int res=0,opn=0,cls=0;
	for(int i=0;i<s.size();i++){
		(kind(s[i])?cls++:opn++);
		if(opn<cls)return cout<<"Impossible",0;
	}
	if(cls!=opn)return cout<<"Impossible",0;
	for(int i=0;i<s.size();i++){
		if(kind(s[i])){
			if(pos.empty())return cout<<"Impossible",0;
			int t=pos.top();pos.pop();
			if(type(s[t])!=type(s[i]))res++;
		}
		else pos.push(i);
	}
	cout<<res;
}