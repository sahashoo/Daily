#include<bits/stdc++.h>
using namespace std;

int Zfind(string &TXT,string &PTRN){
	string Zstr=PTRN+TXT;
	int Zln=Zstr.size();
	vector<int>Z(Zln);
	
	for(int i=1,L=0,R=0;i<Zln;i++){
		if(i<=R)
			Z[i]=min(R-i+1,Z[i-L]);
		
		while(i+Z[i]<Zln&&Zstr[Z[i]]==Zstr[i+Z[i]])
			Z[i]++;
		
		if(i+Z[i]-1>R)
			L=i,R=i+Z[i]-1;
	}
	
	int ocr=0;//number of occurence
	for(int i=0;i<Z.size();i++)
		if(Z[i]>=PTRN.size())//ocr++;
			return i-PTRN.size()+1;
	return -1;//ocr
}

vector<int> ZFunction(string s){
	int n=(int)s.size();
	vector<int>z(n);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

int Check(string TXT,string PTRN){
	if(PTRN.size()==0)return TXT.size()+1;
	string str=PTRN+TXT;
	vector<int>Z=ZFunction(str);
	int res=0;
	for(int i=0;i<Z.size();i++)
		if(Z[i]>=PTRN.size())
			return i-PTRN.size()+1;
	return -1;
}

int32_t main(){
	string s,t;cin>>s>>t;
	cout<<Check(s,t);
}