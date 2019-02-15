#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int cnt[N],res;
queue<int>Q;


int32_t main(){
	int k;string s;
	cin>>k>>s;s+="1";
	int n=s.size(),t=0;	
	if(k==0){
		for(int i=0;i<n;i++){
			if(s[i]=='0')t++;
			else res+=t*(t+1)/2,t=0;
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(s[i]=='0')t++;
			else cnt[i]=t,t=0;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='1')Q.push(i);
			if(Q.size()==k+1){
				res+=cnt[Q.front()]+cnt[Q.back()]+1;
				res+=cnt[Q.front()]*cnt[Q.back()];
				Q.pop();
			}
		}
	}
	cout<<res;
}