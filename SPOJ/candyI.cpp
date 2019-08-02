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

  ll n,total,a,b;
  while(cin>>n && n!=-1){
    ll a[n];
    total=0;
    fr(i,0,n){
      cin>>a[i];
      total+=a[i];
    }

    if(total%n!=0) cout<<-1;
    else{
      multiset<ll> ms;
      multiset<ll>::iterator it;

      fr(i,0,n) ms.insert(a[i]);

      ll ans=0;
      while(*ms.begin()!=*prev(ms.end())){
        ms.insert(*ms.begin()+1);
        ms.insert(*prev(ms.end())-1);
        ms.erase(ms.begin());
        ms.erase(prev(ms.end()));
        ans++;
      }
      cout<<ans;
    }
    cout<<"\n";
  }

  return 0;
}
