#include<bits/stdc++.h>
using namespace std;
int jai,jao,ma,n;
string s;
int main(){
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if((s[i]<124&&s[i]>64)&&s[i]!='_'){
			for(int o=i;o<n;o++){
				if(s[o+1]=='_'||s[o+1]=='('||(s[n-1]!='_'&&o==n-1)){
					ma=max(ma,o-i+1);
					i=o;
					break;
				}
			}
		}
		if(s[i]=='('){
			for(int o=i+1;o<n;o++){
				if(s[o]==')'){
					i=o;
					break;
				}
				if(((s[o]<124&&s[o]>64)&&s[o]!='_')&&(!((s[o-1]<124&&s[o-1]>64)&&s[o-1]!='_'))){
					jai++;
				}
			}
		}
	}
	cout<<ma<<" "<<jai;
}