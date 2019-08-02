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
#define N 300001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll cs,ms;
  cs=a[0];
  if(cs<=m) ms=cs;
  else ms=0;

  if(cs==m){
    cout<<m;
    return 0;
  }

  ll k=0;
  fr(i,1,n){
    cs+=a[i];
    if(cs==m){
      cout<<m;
      return 0;
    }
    else if(cs<m){
      ms=max(ms,cs);
    }
    else{
      while(cs>m){
        cs-=a[k++];
      }
      if(cs==m){
        cout<<m;
        return 0;
      }
      else{
        ms=max(ms,cs);
      }
    }
  }

  cout<<ms;

  return 0;
}
