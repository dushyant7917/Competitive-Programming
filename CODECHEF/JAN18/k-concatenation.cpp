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
#define MAX(a,b,c,d,e,f,g) max(a,max(b,max(c,max(d,max(e,max(f,g))))))
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll ms,cs;
  ll n,k;
  while(t--){
    cin>>n>>k;
    ll a[n];

    fr(i,0,n) cin>>a[i];

    cs=a[0];
    ms=cs;
    fr(i,1,n){
      cs=max(a[i],cs+a[i]);
      ms=max(ms,cs);
    }


    if(k==1) cout<<ms;
    else{
      vector<ll> b;
      fr(i,0,3){
        fr(j,0,n) b.PB(a[j]);
      }
      cs=b[0];
      ms=cs;
      fr(i,1,n){
        cs=max(b[i],cs+b[i]);
        ms=max(ms,cs);
      }
      fr(i,n,2*n){
        cs=max(b[i],cs+b[i]);
        ms=max(ms,cs);
      }
      ll ft=ms;
      if(k==2) cout<<ms;
      else{
        fr(i,2*n,3*n){
          cs=max(b[i],cs+b[i]);
          ms=max(ms,cs);
        }
        ll d=ms-ft;
        cout<<ft+(d*(k-2));
      }
    }

    cout<<"\n";
  }

  return 0;
}
