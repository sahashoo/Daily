#include<bits/stdc++.h>
using namespace std;
string s,t;
set<int>PFS;
vector<int>PF;

int32_t main(){
	cin>>s>>t;
	int sln=s.size(),tln=t.size();
	for(int i=1;i*i<=sln;i++)if(sln%i==0)PFS.insert(i),PFS.insert(sln/i);
	for(int i=1;i*i<=tln;i++){//time
		if(tln%i==0){
			if(PFS.count(i))PF.push_back(i);
			if(PFS.count(tln/i)&&tln/i!=i)PF.push_back(tln/i);
		}
	}
	int cnt=0;
	//for(int i=0;i<PF.size();i++)cout<<PF[i]<<" ";
	//cout<<endl;
	for(int i=0;i<PF.size();i++){
		string a=s.substr(0,PF[i]),aa="";
		string b=t.substr(0,PF[i]),bb="";
		while(aa.size()<sln)aa+=a;
		while(bb.size()<tln)bb+=b;
		if(a==b&&aa==s&&t==bb)cnt++;//cout<<PF[i]<<endl,cnt++;
	}
	cout<<cnt<<endl;;
	
}