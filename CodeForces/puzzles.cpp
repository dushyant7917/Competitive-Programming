#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  ll a[m],min_diff=LLONG_MAX;

  fr(i,0,m) cin>>a[i];

  sort(a,a+m);

  fr(i,0,m-n+1){
    min_diff=min(min_diff,a[i+n-1]-a[i]);
  }

  cout<<min_diff;

  return 0;
}
