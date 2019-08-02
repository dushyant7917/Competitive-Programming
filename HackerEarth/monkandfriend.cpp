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

ll num_ones(ll n){
  ll cnt=0;

  while(n){
      n=n&(n-1);
      cnt++;
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll m,p;
  while(t--){
    cin>>m>>p;
    cout<<num_ones(m^p)<<"\n";
  }

  return 0;
}
