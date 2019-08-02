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

  ll n,m;
  cin>>n>>m;
  vector<ll> v;
  fr(i,0,n) v.PB(0);

  ll a,b,k;
  fr(i,0,m){
    cin>>a>>b>>k;
    v[a-1]+=k;
    if(b<n) v[b]-=k;
  }

  ll mv=v[0];
  fr(i,1,n){
    v[i]+=v[i-1];
    mv=max(mv,v[i]);
  }
  
  cout<<mv;

  return 0;
}
