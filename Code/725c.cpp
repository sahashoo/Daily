///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int U=300;
string s,t1,t2;
int mrk[U];
bool flg;

void fillt(int a,int b){
	int mid=(a+b-1)/2;
	for(int i=mid;i>=0;i--)t1+=s[i];
	for(int i=mid+1;i<s.size();i++)if(s[i]!=s[a])t2+=s[i];
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(mrk,-1,sizeof(mrk));
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(mrk[s[i]]!=-1){
			if(i-mrk[s[i]]==1)return cout<<"Impossible",0;
			else{
				fillt(mrk[s[i]],i);
			}
		}
		mrk[s[i]]=i;
	}
	if(t1.size()>=13){
		for(int i=0;i<13;i++)cout<<t1[i];
		cout<<endl;
		for(int i=0;i<t2.size();i++)cout<<t2[i];
		for(int i=t1.size()-1;i>=13;i--)cout<<t1[i];
	}
	else{
		for(int i=0;i<t1.size();i++)cout<<t1[i];
		//cout<<endl;
		for(int i=t2.size()-1;i>=13;i--)cout<<t2[i];
		cout<<endl;
		for(int i=0;i<13;i++)cout<<t2[i];
	}
}


