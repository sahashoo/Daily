#include<bits/stdc++.h>
using namespace std;
map<int,int> al;
string s;
int n,r;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		al[s[i]]++;
		if(al[s[i]]!=1){
			al[s[i]]=1;
			r++;
		}
	}
	if(al.size()+r>26)	cout<<"-1";
	else{
		cout<<r;
	}
}