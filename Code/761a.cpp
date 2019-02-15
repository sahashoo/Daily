#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll odd,even;
int main(){
	cin>>even>>odd;
	if((odd==even||odd-even==1||even-odd==1)&&(odd||even))	cout<<"YES";
	else cout<<"NO";
}