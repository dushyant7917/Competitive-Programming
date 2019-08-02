#include<bits/stdc++.h>

using namespace std;

int main() {
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  int t=n1+n2+n3;
  int vl[t],i;

  for(i=0;i<t;i++){
    cin>>vl[i];
  }

  sort(vl, vl+t);
  vector<int> x;

  int prv=vl[0],cnt=0;
  for(i=1;i<t+1;i++){ // i < t+1 constraint is used instead of i < t so that last element is also pushed back in the vector
    cout<<prv<<" "<<vl[i]<<"\n";
    if(vl[i]==prv){
      cnt++;
    }
    else{
      if(cnt>=1){
        x.push_back(prv);
      }
      cnt=0;
    }
    prv=vl[i];
  }

  cout<<x.size()<<"\n";
  for(i=0;i<x.size();i++){
    cout<<x[i]<<"\n";
  }

  return 0;
}
