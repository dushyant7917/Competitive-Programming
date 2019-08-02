#include<bits/stdc++.h>
using namespace std;

typedef long int li;
#define loop(a,b) for(li i=a;i<b;i++)

li solve(vector<li> a, vector<li> b, li k){
  priority_queue<li> q1,q2;
  for(li i:a){
    q1.push(i);
  }
  for(li i:b){
    q2.push(-i);
  }

  li i,x,y;
  loop(0,k){
    if(q1.top() <= -q2.top()){
      break;
    }
    x=q1.top();
    q1.pop();
    y=-q2.top();
    q2.pop();
    q1.push(y);
    q2.push(-x);
  }
  while(q2.size()>1){
    q2.pop();
  }
  return q1.top()-q2.top();
}

int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  li n,k;
  cin>>n>>k;
  vector<li> a,b;
  li i,x,y;
  loop(0,n){
    cin>>x;
    a.push_back(x);
  }
  loop(0,n){
    cin>>y;
    b.push_back(y);
  }

  cout<<min(solve(a,b,k),solve(b,a,k));

  return 0;
}
