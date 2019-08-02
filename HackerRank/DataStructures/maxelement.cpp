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
  ll t;
  cin>>t;

  stack<pair<ll,ll> > s,m;
  ll ty,x,ind=0;
  while(t--){
    cin>>ty;
    if(ty==1){
      cin>>x;
      s.push(MP(x,ind));
      if(m.size()==0) m.push(MP(x,ind));
      else{
        if(x>m.top().first) m.push(MP(x,ind));
      }
    }
    else if(ty==2){
      if(s.size() && m.size() && s.top().first==m.top().first && s.top().second==m.top().second) m.pop();
      if(s.size()) s.pop();
    }
    else{
      if(m.size()) cout<<m.top().first<<"\n";
    }
    ind++;
  }

  return 0;
}
