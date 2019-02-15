#include<bits/stdc++.h>
#define size(a) (int)a.size()
using namespace std;
void null(){return ;}
struct node{
	int wrd;//count the end
	//int e[26];//link to son
	map<int,int>e;
}nll;
vector<node>trie;

void initialize(node &a){
	a.wrd=0;
	for(int i=0;i<27;i++)a.e[i]=-1;
}

void add(string s){
	int cur=0;
	for(int i=0;i<size(s);i++){
		char c=s[i];
		if(trie[cur].e[c-'a']==-1){
			trie.push_back(nll);
			trie[cur].e[c-'a']=size(trie)-1;
		}
		cur=trie[cur].e[c-'a']; 
	}
	trie[cur].wrd++;
	return;
}

bool read(string s){
	int cur=0;
	for(int i=0;i<size(s);i++){
		char c=s[i];
		if(i<size(s)-1&&trie[cur].e[c-'a']==-1)return false;
		cur=(trie[cur].e[c-'a']==-1?cur:trie[cur].e[c-'a']);
	}
	if(trie[cur].wrd)return true;
	return false;
}

void del(string s){
	int cur=0;
	for(int i=0;i<size(s);i++){
		char c=s[i];
		if(trie[cur].e[c-'a']==-1)return ;
		cur=trie[cur].e[c-'a'];
	}
	if(trie[cur].wrd)trie[cur].wrd--;
	return;
}

int32_t main(){
	initialize(nll);
	trie.push_back(nll);
	int n,m,k;cin>>n>>m>>k;
	string tmp;
	while(n--)cin>>tmp,add(tmp);
	while(m--)cin>>tmp,del(tmp);
	while(k--)cin>>tmp,cout<<(read(tmp)?"YES":"NO")<<endl;
}