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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    ll diagonal = ceil((sqrt(8.0*n+1.0)-1.0)/2.0);
    ll endpoint = ((diagonal*diagonal)+diagonal)/2;
    ll difference;

    if(n>endpoint) difference=n-endpoint;
    else difference=endpoint-n;

    if(diagonal%2==0) cout<<"TERM "<<n<<" IS "<<(diagonal-difference)<<'/'<<(1+difference)<<"\n";
    else cout<<"TERM "<<n<<" IS "<<(1+difference)<<'/'<<(diagonal-difference)<<"\n";
  }

  return 0;
}
