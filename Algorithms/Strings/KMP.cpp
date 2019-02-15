#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int pfx[maxn];

int kmp(string s,string t){
    //Making Prefixe Array
	int i=1,j=0;
    while(i<s.size()&&j<s.size()){
        if(s[i]==s[j])pfx[i]=j+1,i++,j++;
        else pfx[i]=0,i++;
    }
	//Main
    i=0,j=0;
    while(i<s.size()&&j<t.size()){
        if(j==t.size()-1)return i-t.size()+2;
        else{
            if(s[i]==t[j])i++,j++;
            else(j?j=pfx[j-1]:i++);
        }
    }
    return -1;
}

void arpa(){
	string s;cin>>s;
	int k=0,n=s.size();
	for(int i=1;i<n;i++){
		while(k&&s[i]!=s[k])
			k=f[k];
		k+=(s[i]==s[k]);
		f[i+1]=k;
    }
}

int main(){
	string s,t;
	cin>>s>>t;
	int n=kmp(s,t);
	if(n==-1)	cout<<"NOT FOUND!"<<endl;
	else cout<<n<<" "<<t.size()+n<<endl;
}
