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

  ll n,k,m_sum,mn,mn_sum;
  while(t--){
    cin>>n>>k;

    ll a[n];
    fr(i,0,n){
      cin>>a[i];
    }

    sort(a,a+n);

    mn=((n-k)>(n/2))?k:(n-k);
    mn_sum=0;
    m_sum=0;
    fr(i,0,mn) mn_sum+=a[i];
    fr(i,mn,n) m_sum+=a[i];

    cout<<m_sum-mn_sum<<"\n";
  }
  return 0;
}
