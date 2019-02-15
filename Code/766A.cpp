#include<bits/stdc++.h>
using namespace std;
string s,p;

int main(){
  cin>>s>>p;
  if(s==p)cout<<-1<<endl;
  else cout<<max(s.size(),p.size())<<endl;
}