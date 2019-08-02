#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int i,a,b,max_lead=-1,winner,t1=0,t2=0;
  for(i=1;i<=n;i++){
    cin>>a>>b;
    t1+=a;
    t2+=b;
    if(t1>t2 && (t1-t2)>max_lead){
      max_lead=t1-t2;
      winner=1;
      continue;
    }
    if(t1<t2 && (t2-t1)>max_lead){
      max_lead=t2-t1;
      winner=2;
    }
  }
  cout<<winner<<" "<<max_lead;
  return 0;
}
