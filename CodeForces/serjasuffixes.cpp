#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
  
  ll n,m,x;
  cin>>n>>m;
  ll a[n],suff[n];
  fr(i,0,n) cin>>a[i];
  set<ll> s;
  for(ll i=n-1;i>=0;i--){
    s.insert(a[i]);
    suff[i]=s.size();
  }
  fr(i,0,m){
    cin>>x;
    cout<<suff[x-1]<<"\n";
  }

  return 0;
}
