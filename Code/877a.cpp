///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
string TXT;

int ss(string PTRN){
	string Zstr=PTRN+TXT;
	int Zln=Zstr.size();
	vector<int>Z(Zln,0);	
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
		if(Z[i]>=PTRN.size())ocr++;
			// return i-PTRN.size()+1;
	return ocr;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>TXT;
	int res=0;
	if(ss("Ann")+ss("Danil")+ss("Olya")+ss("Slava")+ss("Nikita")==1)cout<<"YES";
	else cout<<"NO";
}
