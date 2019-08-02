#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  vector<ll> am[n];

  ll a,b;
  fr(i,0,m){
    cin>>a>>b;
    am[a].pb(b);
  }

  ll q;
  cin>>q;
  bool flag=false;
  fr(i,0,q){
      cin>>a>>b;
      fr(j,0,am[a].size()){
          if(am[a][j]==b){
              cout<<"YES\n";
              flag=true;
              break;
          }
      }
      if(!flag) cout<<"NO\n";
  }

  return 0;
}
