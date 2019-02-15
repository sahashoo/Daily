#include<bits/stdc++.h>
using namespace std;
string s;
int ma,arr[1000005][10];
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		ma=max(ma,s[i]-48);
		for(int o=0;o<s[i]-48;o++){
			arr[i][o]=1;
		}
	}
	cout<<ma<<endl;
	for(int i=0;i<ma;i++){
		int u=0;
		for(int o=0;o<s.size();o++){
			if(arr[o][i]==1)	u++;
			if(u>0)	cout<<arr[o][i];
		}
		cout<<endl;
	}
}