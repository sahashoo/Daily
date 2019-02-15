#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;

int main(){
	cin>>n>>k;
	cout<<(log2((k&(-k)))+1);
}