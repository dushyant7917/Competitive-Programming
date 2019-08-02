#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 10000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll solve(ll n){
  stack<ll> pfs;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      pfs.push(i);
      n/=i;
    }
  }
  if(n>1) pfs.push(n);

  ll d=1,ans=1;
  while(!pfs.empty()){
    d*=pfs.top();
    pfs.pop();
    ans+=d;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll ans=0;
  fr(i,0,n){
    ans+=solve(a[i]);
  }

  cout<<ans;

  return 0;
}
