#include<bits/stdc++.h>
using namespace std;
int n;
char c[5];

int main(){
	cin>>n;
	c[0]='a';
	c[1]='b';
	c[2]='b';
	c[3]='a';
	for(int i=0;i<n;i++)cout<<c[i%4];
}