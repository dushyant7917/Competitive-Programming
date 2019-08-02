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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  ll a,b,g;
  while(t--){
    cin>>n;

    ll k=0;
    vector< pair<ll,ll> > edges[n+1];
    set<ll> s;
    fr(i,0,n-1){
      cin>>a>>b>>g;
      edges[a].PB(make_pair(b,g));
      edges[b].PB(make_pair(a,g));
      if(g==1) {
        k++;
        s.insert(a);
        s.insert(b);
      }
    }

    ll cnt=0;
    set<ll>::iterator itr;
    for(itr=s.begin();itr!=s.end();itr++){
      fr(i,0,edges[(*itr)].size()){
        if(edges[(*itr)][i].second!=1) cnt++;
      }
    }

    if(k==0) cout<<0<<"\n";
    else{
      cout<<1+pow(2,cnt)-1<<"\n";
    }

  }

  return 0;
}
