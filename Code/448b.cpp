#include<bits/stdc++.h>
using namespace std;
string s,t;
map<char,int> subs,subt;
main(){
  cin>>s>>t;
  for(int i=0;i<s.size();i++)subs[s[i]]++;
  for(int i=0;i<t.size();i++)subt[t[i]]++;
  if(subs==subt){cout<<"array";return 0;}
  for(int i=0;i<t.size();i++)if(subt[t[i]]>subs[t[i]]){cout<<"need tree";return 0;}
  int i=0,j=0;
  while(i<s.size()&&j<t.size()){
    if(s[i]==t[j]){i++;j++;}
    else i++;
    if(j==t.size()){cout<<"automaton";return 0;}
  }
  cout<<"both";
}