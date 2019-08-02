#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k,x;
  cin>>n>>k;

  set<ll> ms;

  fr(i,0,n){
    cin>>x;
    ms.insert(x);
  }

  ll sub=0,mn;
  fr(i,0,k){
    if(!SZ(ms)){
      cout<<0<<"\n";
      continue;
    }

    mn=*(ms.begin());
    ms.erase(ms.find(mn));

    if(mn-sub) cout<<mn-sub<<"\n";
    else cout<<0<<"\n";

    sub=mn;
  }

  return 0;
}
