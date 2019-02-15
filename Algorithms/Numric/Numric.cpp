#include<bits/stdc++.h>
#define int long long 
using namespace std;

bool prime_check(int a){
	for(int i=2;i*i<=a;i++)
		if(a%i==0)return false;
	return true;
}

void gharbal(){
	mrk[1]=true;
	for(int i=2;i<MAXN;i++){
		if(mrk[i]==false){
			int d=i;
			primes.push_back(i);
			while(d+i<MAXN){
				d+=i;
				mrk[d]++;
			}
		}
	}
}

void big_phi(){
	mrk[1]=true;
	for(int i=0;i<MAXN;i++)phi[i]=i;
	for(int i=2;i<MAXN;i++){
		if(mrk[i]==false){
			int d=i+i;
			while(d<MAXN){
				mrk[d]=true;
				phi[d]=phi[d]*(i-1);
				phi[d]/=i;
				d+=i;
			}
			phi[i]=i-1;
		}
	}
}

int find_big_phi(int k){
	int ans=k;
	int save_n=k;
	for(int i=2;i*i<=save_n;i++)
		if(k%i==0){
			ans*=i-1;
			ans/=i;
			while(k%i==0)k/=i;
		}
	if(k>1)ans*=k-1,ans/=k;
	return ans;
}

int32_t main(){
	
}