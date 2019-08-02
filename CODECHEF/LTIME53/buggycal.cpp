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

void ans(ll n,ll m){
  vector<ll> a,b;
  stack<ll> s;

  while(n>0){
    a.PB(n%10);
    n/=10;
  }
  while(m>0){
    b.PB(m%10);
    m/=10;
  }

  ll d,i,j;

  for(i=0,j=0;i<a.size()&&j<b.size();i++,j++){
    d=(a[i]+b[i])%10;
    s.push(d);
  }

  while(i<a.size()){
    d=a[i]%10;
    s.push(d);
    i++;
  }
  while(j<b.size()){
    d=b[j]%10;
    s.push(d);
    j++;
  }

  queue<ll> q;
  bool f=false;
  while(!s.empty()){
    if(s.top()!=0){
      f=true;
    }
    if(f) q.push(s.top());
    s.pop();
  }

  if(q.size()==0) cout<<0;
  else{
    while(!q.empty()){
      cout<<q.front();
      q.pop();
    }
  }
  cout<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m;
  while(t--){
    cin>>n>>m;
    ans(n,m);
  }

  return 0;
}
