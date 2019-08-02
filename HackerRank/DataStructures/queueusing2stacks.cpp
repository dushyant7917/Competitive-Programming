#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll q;
  cin>>q;

  stack<ll> back,front;
  ll t,x;
  while(q--){
    cin>>t;
    if(t==1){
      cin>>x;
      back.push(x);
    }
    else{
      if(front.empty()){
        while(back.size()){
          front.push(back.top());
          back.pop();
        }
      }
      if(t==2) front.pop();
      if(t==3) cout<<front.top()<<"\n";
    }
  }

  return 0;
}
