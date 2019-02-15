///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7;
int n,m,a[maxn],b[maxn];
vector<int>za,zb;

void input(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	for(int i=1;i<n;i++)za.push_back(a[i]-a[i-1]);
	for(int i=1;i<m;i++)zb.push_back(b[i]-b[i-1]);
	//cout<<"HERE"<<endl;;
}

vector<int> ZFUNC(vector<int> &s){
//	cout<<"HERE"<<endl;
	int ss=s.size();
	vector<int>z(ss);
	for(int i=1,l=0,r=0;i<ss;i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(z[i]+i<ss&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

int NOA(){
	//cout<<"here"<<endl;
    if(zb.size()==0)return za.size()+1;
    vector<int>str=zb;
    str.insert(str.end(),za.begin(),za.end());
    vector<int>z=ZFUNC(str);
    int res=0;
    for(int i=zb.size();i<z.size();i++) {
        if(z[i]>=zb.size())res++;
    }
   return res;
}

int32_t main(){
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	cout<<NOA();
}
