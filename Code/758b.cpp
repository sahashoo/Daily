#include<bits/stdc++.h>
using namespace std;
string ja[4],s,ch="RBYG";
int j[4];

int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i%4==0){
			if(s[i]=='!')	j[0]++;
			else	ja[0]=s[i];
		}
		if(i%4==1){
			if(s[i]=='!')	j[1]++;
			else	ja[1]=s[i];
		}
		if(i%4==2){
			if(s[i]=='!')	j[2]++;
			else	ja[2]=s[i];
		}
		if(i%4==3){
			if(s[i]=='!')	j[3]++;
			else	ja[3]=s[i];
		}
	}
	for(int i=0;i<=4;i++){
		for(int o=0;o<4;o++){
			if(ja[o][0]==ch[i]){
				cout<<j[o]<<endl;
				break;
			}
		}
	}
}