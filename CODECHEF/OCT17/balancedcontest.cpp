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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,p;
  while(t--){
    cin>>n>>p;
    map<string,ll> mp;
    ll s;
    fr(i,0,n){
      cin>>s;
      if(s >= p/2) mp["cakewalk"]++;
      else if(s <= p/10) mp["hard"]++;
      else {}
    }
    if(mp["cakewalk"]!=1 || mp["hard"]!=2){
      cout<<"no\n";
    }
    else cout<<"yes\n";
  }

  return 0;
}
