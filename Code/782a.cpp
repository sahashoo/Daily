#include<bits/stdc++.h>
using namespace std;
int n,ans;
set<int>s;

int main(){
	cin>>n;
	for(int i=0;i<2*n;i++){
		int a;
		cin>>a;
		if(s.find(a)==s.end()){s.insert(a);int m=s.size();ans=max(ans,m);}
		else{s.erase(a);int m=s.size();ans=max(ans,m);}
	}
	cout<<ans;
}