#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,px,py;

int main(){
	cin>>x>>y>>a>>b>>px>>py;
	if(abs(x-a)%px==0&&abs(y-b)%py==0&&((abs(y-b)/py)%2==(abs(x-a)/px)%2))cout<<"YES";
	else cout<<"NO";
}