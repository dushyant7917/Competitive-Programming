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

  ll n;
  while(t--){
    cin>>n;
    ll a[n],b[n];
    fr(i,0,n) cin>>a[i];
    fr(i,0,n) cin>>b[i];
    unordered_set<ll> s;
    set<ll>::iterator it;
    fr(i,0,n){
      s.insert(a[i]%b[i]);
    }
    for(it=s.begin();it!=s.end();it++){
      cout<<(*it)<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
