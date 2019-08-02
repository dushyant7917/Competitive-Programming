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

struct Num{
  ll n;
  ll c;
};

ll change_count(ll n){
  ll r=sqrt(n);
  if(r*r==n) return 0;
  else if((n-(r*r)) < (((r+1)*(r+1))-n)){
    return (n-(r*r));
  }
  else return (((r+1)*(r+1))-n);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  ll psc=0;
  fr(i,0,n){
    cin>>a[i];
    if(change_count(a[i])==0) psc++;
  }

  if(psc==n/2){
    cout<<0;
  }
  else if(psc<(n/2)){
    vector<ll> b;
    ll cc;
    fr(i,0,n){
      cc=change_count(a[i]);
      if(cc!=0) b.PB(cc);
    }

    sort(b.begin(),b.end());

    ll cnt=n-b.size();
    ll ans=0;
    for(ll i=0;i<b.size(),cnt<n/2;i++){
      ans+=b[i];
      cnt++;
    }

    cout<<ans;
  }
  else{
    vector<ll> b;
    ll ans=0;
    fr(i,0,n){
      if(a[i]!=0 && change_count(a[i])==0){
        b.PB(a[i]);
        ans++;
        if(psc-(n/2)==b.size()) break;
      }
    }
    if(psc-(n/2)==b.size()) cout<<ans;
    else{
      fr(i,0,n){
        if(a[i]==0){
          b.PB(a[i]);
          ans+=2;
          if(psc-(n/2)==b.size()){
            cout<<ans;
            break;
          }
        }
      }
    }
  }

  return 0;
}
