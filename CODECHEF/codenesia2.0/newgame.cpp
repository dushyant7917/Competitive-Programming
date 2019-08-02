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

  ll t;
  cin>>t;

  ll n,c;
  while(t--){
    cin>>n;
    ll a[n];
    fr(i,0,n) cin>>a[i];
    cin>>c;

    sort(a,a+n);

    ll ind;
    ll cnt=0;
    fr(i,0,n-2){
      fr(j,i+1,n-1){
        ind=lower_bound(a+j+1,a+n,c-a[i]-a[j]+1)-a;
        if(ind<n){
          cnt+=(n-ind);
        }
      }
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
