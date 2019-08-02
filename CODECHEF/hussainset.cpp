#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
#define loop(a,b) for(li i=a;i<b;i++)

int main(){
  li n,m;
  cin>>n>>m;
  li hs[n];
  loop(0,n){
    cin>>hs[i];
  }

  sort(hs,hs+n);

  queue<li> q1,q2;
  for(li k=n-1;k>=0;k--){
    q1.push(hs[k]);
  }

  li num,x,j=1;
  loop(0,m){
    cin>>x;
    for(;j<=x;j++){
      if(q1.front()>=q2.front()){
        num=q1.front();
        q1.pop();
      }
      else{
        num=q2.front();
        q2.pop();
      }
      if(num/2>0){q2.push(num/2);}
    }
    cout<<num<<"\n";
  }

  return 0;
}
