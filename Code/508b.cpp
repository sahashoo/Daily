#include<bits/stdc++.h>
using namespace std;
string s;
int ja=-10;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]%2==0){
			if(s[s.size()-1]>s[i]){
				swap(s[s.size()-1],s[i]);
				cout<<s;
				return 0;
			}
			ja=i;
		}
	}
	if(ja==-10)	cout<<"-1";
	else{
		swap(s[s.size()-1],s[ja]);
		cout<<s;
	}
}