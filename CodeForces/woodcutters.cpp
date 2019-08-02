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

  ll n;
  cin>>n;

  ll x[n],h[n];
  fr(i,0,n) cin>>x[i]>>h[i];

  if(n<=2) cout<<n;
  else{
    ll cnt=0,prv=x[0];
    fr(i,1,n-1){
      if(x[i]-h[i]>prv){
        cnt++;
        prv=x[i];
      }
      else if(x[i]+h[i]<x[i+1]){
        cnt++;
        prv=x[i]+h[i];
      }
      else prv=x[i];
    }
    cout<<2+cnt;
  }

  return 0;
}
