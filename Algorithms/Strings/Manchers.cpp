//longest parlindom substring
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

void manchers(string s){
    int C=1,R=2,iMirror,maxLPSLength=0,maxLPSCenterPosition=0,start=-1,end=-1,L[maxn],N=2*s.size()+1;
    L[0]=0,L[1]=1;
    for(int i=2;i<N;i++){
        iMirror=2*C-i;
        L[i]=0;
        if(R-i>0)L[i]=min(L[iMirror],R-i);
        while(((i+L[i])<N&&(i-L[i])>0)&&(((i+L[i]+1)%2==0)||(s[(i+L[i]+1)/2]==s[(i- L[i]-1)/2])))L[i]++;
        if(L[i]>maxLPSLength)maxLPSLength=L[i],maxLPSCenterPosition=i;
        if(i+L[i]>R)C=i,R=i+L[i];
    }
    start=(maxLPSCenterPosition-maxLPSLength)/2;
    end=start+maxLPSLength-1;
    for(int i=start;i<=end;i++)cout<<s[i];
}

int main(){
    string s;cin>>s;
    manchers(s);
}
